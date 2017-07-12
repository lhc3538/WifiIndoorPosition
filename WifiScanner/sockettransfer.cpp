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
    rul = send(fd_sock,&length,sizeof(int),0);
    char *p = (char*) &length;
    printf("[0]=%d",p[0]);
    printf("[1]=%d",p[1]);
    printf("[2]=%d",p[2]);
    printf("[3]=%d",p[3]);
    cout << "int size=" << sizeof(int) << endl;
    cout << "send size=" << length << endl;
    if (rul <= 0) {
        perror("send length error");
        return -1;
    }
    //send the buffer
    cout << "send data:\n" << str.data() << endl;
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
    int length;
    rul = recv(fd_sock,&length,sizeof(int),0);
//    cout << "recv size=" << length << endl;
    if (rul <= 0) {
        perror("recv length error");
        return string();
    }
    char *p = (char*) &length;
    printf("[0]=%d",p[0]);
    printf("[1]=%d",p[1]);
    printf("[2]=%d",p[2]);
    printf("[3]=%d",p[3]);
    int test;
    char *tp = (char*) &test;
    tp[0] = p[3];
    tp[1] = p[2];
    tp[2] = p[1];
    tp[3] - p[0];
    cout << "test size:" << test << endl;
    cout << "recv size:" << length << endl;
    length = test;
    //recv the buffer
    char *buffer = (char*)malloc(length+1);
    rul = recv(fd_sock,buffer,length,0);
    if (rul <= 0) {
        perror("recv data error");
        return string();
    }
    buffer[length] = 0;
    string str = string(buffer);
    free(buffer);
    return str;
}
