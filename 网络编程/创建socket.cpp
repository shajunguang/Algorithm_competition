#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>
#include<assert.h>
#include<stdio.h>
#include<string.h>
#include <netdb.h>
int socket(int domain,int type,int protocol)__THROW; //创建
//domain表示使用哪个协议族,PF_UNIX --UNIX本地域协议族 PF_INET--TCP/IPv4协议族
//PF_INET6--TCP/IPv6协议族,地址就改为AF,两者值相同的
//type指定服务类型 SOCK_STREAM服务(TCP流服务) SOCK_UGRAM(数据报UDP).传输层
//返回一个socket文件描述符，失败返回-1并设置errno
int bind(int sockfd,const struct sockaddr* my_addr, socklen_t addrlen)__THROW; //命名
//my_addr所指的socket地址分配给未命名的sockfd文件描述符，addrlen是地址长度
//失败返回EACCES表示没有权限，例如端口号0-1023，EADDRINUSE正在使用的端口
int listen(int sockfd,int backlog)__THROW;//监听backlog最大长度监听

int accept(int sockfd,struct sockaddr *addr, socklen_t *addrlen);//接受连接
//只是从监听队列中取出连接，而不论处于何种状态，更不关心任何网络状况的变化
int connect(int sockfd, const struct sockaddr *serv_addr, socklen_t addrlen);
//客服端主动与服务器建立连接
int close(int fd); //关闭 fd是待关闭的socket
//将fd引用计数减1，需要在父进程和子进程都使用close
int shutdown(int sockfd,int howto)__THROW;//相对close而言为网络编程设计的，可以选择关闭读或者写
ssize_t recv(int sockfd,void *buf,size_t len,int flags); //TCP的读写，对于带外数据会出现偏移urg参数
ssize_t send(int sockfd,const void *buf,size_t len,int flags);
ssize_t recvfrom(int sockfd,void *buf,size_t len,int flags, struct sockaddr* src_addr,socklen_t* addrlen);
ssize_t sendto(int sockfd,void *buf,size_t len,int flags, struct sockaddr* src_addr,socklen_t* addrlen);
//UDP读写，参数增加发送端的socket地址
int sockatmark(int sockfd)__THROW; //判断带外标记
int getsockname(int sockfd,struct sockaddr* address,socklen_t* address_len)__THROW;
int getpeername(int sockfd,struct sockaddr* address,socklen_t* address_len)__THROW;
//获取地址信息,第一个本段socket地址，第二个远端socket地址

int main()
{
    auto ht = gethostbyname("liu");
    printf("%s\n",ht->h_name);
    //fork(); /* 1+1=2 */
    //fork() /* 2+2=4 */ && fork() /* 4+2=6 */ || fork() /* 6+4=10 */;
    //fork()&&fork()||fork();
    //fork(); /* 10*2=20 */
    //printf("+\n");
}