#ifndef SOCKETCLIENT_H
#define SOCKETCLIENT_H

#include <string>

using namespace std;

class SocketConnector
{
public:
    SocketConnector();
    int ConnectServer(char *ip,int port);
};

#endif // SOCKETCLIENT_H
