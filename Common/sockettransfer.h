#ifndef SOCKETTRANSFER_H
#define SOCKETTRANSFER_H

#define DIFFER_ENDIAN 1

#include <string>

using namespace std;

class SocketTransfer
{
public:
    SocketTransfer(int fd);
    int Send(string str);
    string Recv();

private:
    int TransfEndian(int num);

private:
    int fd_sock;

};

#endif // SOCKETTRANSFER_H
