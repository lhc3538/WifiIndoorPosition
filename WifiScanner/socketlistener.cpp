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

#include "socketlistener.h"

SocketListener::SocketListener(int port, int queue)
{
    ///定义sockfd
    fd_ser = socket(AF_INET,SOCK_STREAM, 0);
    ///定义sockaddr_in
    struct sockaddr_in server_sockaddr;
    server_sockaddr.sin_family = AF_INET;
    server_sockaddr.sin_port = htons(port);
    server_sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    ///bind，成功返回0，出错返回-1
    if(bind(fd_ser,(struct sockaddr *)&server_sockaddr,sizeof(server_sockaddr))==-1)
    {
        perror("bind error");
        fd_ser = -1;
    }
    printf("监听%d端口\n",port);
    ///listen，成功返回0，出错返回-1
    if(listen(fd_ser,queue) == -1)
    {
        perror("listen error");
        fd_ser = -1;
    }
}

int SocketListener::WaitClient()
{
    ///客户端套接字
   struct sockaddr_in client_addr;
   socklen_t length = sizeof(client_addr);
   printf("等待客户端连接\n");
   ///成功返回非负描述字，出错返回-1
   int conn = accept(fd_ser, (struct sockaddr*)&client_addr, &length);
   if(conn<0)
   {
       perror("accept error");
       return -1;
   }
   printf("客户端成功连接\n");
   return conn;
}
