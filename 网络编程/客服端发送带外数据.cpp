#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<assert.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
    if(argc<=2)
    {
        printf("usage: %s ip_address port_number\n",basename(argv[0])); //basename返回文件名
        return 1;
    }
    const char* ip=argv[1];
    int port = atoi(argv[2]);

    struct sockaddr_in server_address;
    bzero(&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    inet_pton(AF_INET,ip,&server_address.sin_addr); //将主机字节序转为网络字节序 ip地址
    server_address.sin_port = htons(port); //port端口

    int sockfd = socket(PF_INET, SOCK_STREAM, 0); //创建socket
    assert(sockfd>=0);
    //请求连接服务器
    if(connect(sockfd, (struct sockaddr*)&server_address, sizeof(server_address))<0)
    {
        printf("Connection failed\n");
    }
    else
    {
        const char* oob_data = "abc"; //带外数据，即紧急数据
        const char* normal_data = "123";
        send(sockfd, normal_data, strlen(normal_data),0);
        send(sockfd, oob_data, strlen(oob_data),MSG_OOB);
        send(sockfd, normal_data, strlen(normal_data),0);
    }
    close(sockfd); //关闭连接
    return 0;
}