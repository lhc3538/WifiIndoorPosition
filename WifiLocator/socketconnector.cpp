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

#include "socketconnector.h"

SocketConnector::SocketConnector()
{

}

int SocketConnector::ConnectServer(char *ip, int port)
{
    ///定义sockfd
    int fd_sock = socket(AF_INET,SOCK_STREAM, 0);
    ///定义sockaddr_in
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);  ///服务器端口
    servaddr.sin_addr.s_addr = inet_addr(ip);  ///服务器ip
    printf("连接%s:%d\n",ip,port);
    ///连接服务器，成功返回0，错误返回-1
    if (connect(fd_sock, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("connect error");
        return -1;
    }
    printf("服务器连接成功\n");
    return fd_sock;
}
