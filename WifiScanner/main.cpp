#include <iostream>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

#include "socketlistener.h"
#include "../Common/sockettransfer.h"

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
    sockListener.Close();
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
        ///recv cmd from client
        string cmd_str = sockTransfer.Recv();
        cout << "cmd_str.size=" << cmd_str.size() << endl;
        if (cmd_str.size() == 0)
        {
            perror("client offline\n");
            break;
        }

        ///execute the cmd of client
        string cmd_rul = executeCMD(cmd_str);

        ///send the result of cmd-running to client
        int ret = sockTransfer.Send(cmd_rul);
        if (ret < 0)
        {
            perror("client offline\n");
            break;
        }
    }
    close(fd_cli);
    return NULL;
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
