#include <iostream>
#include <string>
#include <stdio.h>
#include <pthread.h>

#include "socketlistener.h"
#include "sockettransfer.h"

using namespace std;

string executeCMD(string cmd);
void* serveClient(void* fd_p);

int main(int argc, char *argv[])
{
    int ret;
    SocketListener sockListener(3538,20);
    while(1)
    {
        int cli = sockListener.WaitClient();

        pthread_t pt;
        ret = pthread_create (&pt, NULL, &serveClient, &cli);
        if (ret != 0)
        {
            perror ("pthread create error");
        }
        pthread_detach(pt);
    }
    return 0;
}

/**
 * @brief serveClient
 * @param fd_p
 * @return
 */
void* serveClient(void* fd_p)
{
    int fd_cli = *(int *)fd_p;
    cout << "fd_cli=" << fd_cli << endl;
    while(1)
    {
        SocketTransfer sockTransfer(fd_cli);
        string cmd_str = sockTransfer.Recv();
        if (cmd_str.empty())
        {
            printf("client offline\n");
            break;
        }
        string cmd_rul = executeCMD(cmd_str);
        sockTransfer.Send(cmd_rul);
    }
}

/**
 * @brief executeCMD
 * @param cmd
 * @return
 */
string executeCMD(string cmd)
{
    string rul;
    char buf_rul[1024] = {0};
    FILE *ptr;
    if((ptr=popen(cmd.data(), "r"))!=NULL)
    {
        while(fgets(buf_rul, 1024, ptr)!=NULL)
        {
            rul.append(buf_rul);
            printf("%s",buf_rul);
        }
        pclose(ptr);
        ptr = NULL;
    }
    else
    {
        printf("popen %s error\n", cmd.data());
    }
    return rul;
}
