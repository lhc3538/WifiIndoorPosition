#ifndef SOCKETLISTENER_H
#define SOCKETLISTENER_H


class SocketListener
{
public:
    SocketListener(int port,int queue);
    int WaitClient();

private:
    int fd_ser;
};

#endif // SOCKETLISTENER_H
