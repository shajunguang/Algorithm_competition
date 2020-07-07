#include<sys/select.h>
#include<poll.h>
#include<sys/epoll.h>
int select(int nfds,fd_set* readfds, fd_set* writefds,fd_set* exceptfds,struct timeval* timeout);
//监听用户感兴趣的文件描述符的可读，可写和异常事件，返回文件描述符总数
int poll(struct pollfd* fds, nfds_t nfds,int timeout);
//指定时间内轮询一定数量的文件描述符，返回文件描述符总数
int epoll_create(int size)__THROW;
//创造一个额外的文件描述符
int epoll_ctl(int epfd,int op,int fd,struct epoll_event* event)__THROW;
//操纵内核事件表
int epoll_wait(int epfd,struct epoll_event* event, int maxevents,int timeout);
//在一段超时时间内等待一组文件描述符的事件，效率比select,poll高