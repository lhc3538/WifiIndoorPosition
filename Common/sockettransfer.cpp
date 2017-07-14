#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/shm.h>

#include "sockettransfer.h"

SocketTransfer::SocketTransfer(int fd)
{
    fd_sock = fd;
}

int SocketTransfer::Send(string str)
{
    int rul;
    //send the buffer size
    int length = str.size();
//    cout << "send size:" << length << endl;
    rul = send(fd_sock,&length,sizeof(int),0);
    if (rul <= 0) {
        perror("send length error");
        return -1;
    }

    //send the buffer
    rul = send(fd_sock,str.data(),length,0);
    if (rul <= 0) {
        perror("send data error");
        return -1;
    }
    return 0;
}

string SocketTransfer::Recv()
{
    int rul;

    //recv the size of buffer
    int length = 0;
    rul = recv(fd_sock,&length,sizeof(int),0);
    if (rul <= 0) {
        perror("recv length error");
        return string("");
    }
//    cout << "length_ori=" << length << endl;
#if DIFFER_ENDIAN == 1
    length = TransfEndian(length);
#endif
//    cout << "length=" << length << endl;
    //recv the buffer
    char *buffer = (char*)malloc(length+1);
    rul = 0;
    while(rul != length)
    {
        int ret = recv(fd_sock,buffer+rul,length-rul,0);
        cout << "ret=" << ret << endl;
        if (ret <= 0) {
            perror("recv data error");
            return string("");
        }
        rul += ret;
    }

    buffer[length] = 0;
    string str = string(buffer);
    free(buffer);
    return str;
}

#if DIFFER_ENDIAN == 1
int SocketTransfer::TransfEndian(int num)
{
    int rul = 0;
    char *p = (char*) &num;
    char *tp = (char*) &rul;
    tp[0] = p[3];
    tp[1] = p[2];
    tp[2] = p[1];
    tp[3] = p[0];
    return rul;
}
#endif
