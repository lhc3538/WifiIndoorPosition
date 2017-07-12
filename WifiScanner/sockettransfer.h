#ifndef SOCKETTRANSFER_H
#define SOCKETTRANSFER_H

#include <string>

using namespace std;

class SocketTransfer
{
public:
    SocketTransfer(int fd);
    int Send(string str);
    string Recv();

private:
    int fd_sock;
};

#endif // SOCKETTRANSFER_H
