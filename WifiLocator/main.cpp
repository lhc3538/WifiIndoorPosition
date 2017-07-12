#include <iostream>
#include "socketconnector.h"
#include "sockettransfer.h"

using namespace std;

int main(int argc, char *argv[])
{
    SocketConnector sockConnector;
    int fd_cli = sockConnector.ConnectServer("192.168.1.131",3538);
//    int fd_cli = sockConnector.ConnectServer("127.0.0.1",3538);
    SocketTransfer sockTransfer(fd_cli);
    sockTransfer.Send("ifconfig");
    string str = sockTransfer.Recv();
    cout << "recv from server:\n" << str << endl;

    sockTransfer.Send("ls");
    str = sockTransfer.Recv();
    cout << "recv from server:\n" << str << endl;

    sockTransfer.Send("pwd");
    str = sockTransfer.Recv();
    cout << "recv from server:\n" << str << endl;
    return 0;
}
