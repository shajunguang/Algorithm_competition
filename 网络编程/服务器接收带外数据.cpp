#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<assert.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>

#define BUF_SIZE 1024

int main(int argc,char* argv[])
{
    if(argc<=2)
    {
        printf("usage: %s ip_address port_number\n",basename(argv[0])); //basename返回文件名
        return 1;
    }
    const char* ip=argv[1];
    int port = atoi(argv[2]);

    struct sockaddr_in address;
    bzero(&address, sizeof(address));
    address.sin_family = AF_INET;
    inet_pton(AF_INET,ip,&address.sin_addr); //将主机字节序转为网络字节序 ip地址
    address.sin_port = htons(port); //port端口

    int sock = socket(PF_INET, SOCK_STREAM, 0); //创建socket
    assert(sock>=0);

    int ret = bind(sock, (struct sockaddr*)&address, sizeof(address));
    //分配socket
    assert(ret!=-1);

    ret=listen(sock,5); //监听端口
    assert(ret!=-1);

    struct sockaddr_in client;
    socklen_t client_addrlength=sizeof(client);
    int connfd = accept(sock, (struct sockaddr*)&client,&client_addrlength);
    sleep(30); //这里设置等待时间
    //服务器接受客服端的连接
    if(connfd<0)
    {
        printf("errno is: %d\n",errno);
    }
    else
    {
        char buffer[BUF_SIZE];
        memset(buffer,'\0',BUF_SIZE);
        ret = recv(connfd,buffer,BUF_SIZE-1,0);
        printf("Got %d bytes of normal data '%s'\n",ret,buffer);

        memset(buffer,'\0',BUF_SIZE);
        ret = recv(connfd,buffer,BUF_SIZE-1,MSG_OOB);
        printf("Got %d bytes of oob data '%s'\n",ret,buffer);

        memset(buffer,'\0',BUF_SIZE);
        ret = recv(connfd,buffer,BUF_SIZE-1,0);
        printf("Got %d bytes of normal data '%s'\n",ret,buffer);

        close(connfd); //先关闭连接
    }

    close(sock); //关闭socket监听
    return 0;
}