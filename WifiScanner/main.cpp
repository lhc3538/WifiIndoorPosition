#include <iostream>
#include <string>
#include <stdio.h>

#include "socketlistener.h"
#include "sockettransfer.h"

using namespace std;

string executeCMD(const char *cmd)
{
    string rul;
    char buf_rul[1024] = {0};
    FILE *ptr;
    if((ptr=popen(cmd, "r"))!=NULL)
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
        printf("popen %s error\n", cmd);
    }
    return rul;
}

int main(int argc, char *argv[])
{
    SocketListener sockListener(3538,20);
    int cli = sockListener.WaitClient();
    string str = executeCMD("ifconfig");
    SocketTransfer sockTransfer(cli);
    sockTransfer.Send(str);
    cout << "recv:\n" << sockTransfer.Recv() << endl;
//    string str = executeCMD("ifconfig");
//    cout << str;
    return 0;
}
