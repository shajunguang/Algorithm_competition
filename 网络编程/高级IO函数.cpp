#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/uio.h>
#include<sys/sendfile.h>
#include<sys/mman.h>
#include<fcntl.h>
int pipe(int fd[2])__THROW;
//用于创建一个管道，实现进程间通信。创建文件描述符fd[0]和fd[1]分别构成管道的两端。
//fd[1]只能写数据,fd[0]只能读数据，都是阻塞的，返回文件描述符
int socketpair(int domain,int type,int protocol,int fd[2])__THROW;
//和socket创建类似，不过domain只能用AF_UNIX(unix本地协议).双向管道可读可写，返回文件描述符
int dup(int file_descriptor)__THROW;
int dup2(int file_descriptor,int file_descriptor_two)__THROW;
//复制原来的文件描述符，却不继承原来的属性，CGI服务器的基本原理
//将服务器的标注输出的内容，直接发送到客服端连接对应的socket上，输出被客服端获得
ssize_t readv(int fd, const struct iovec* vector,int count); //分散读
ssize_t writev(int fd, const struct iovec* vector,int count); //集中写
ssize_t sendfile(int out_fd,int in_fd,off_t* offset, size_t count)__THROW;
//两个文件描述符之间的直接传递数据，零拷贝
void* mmap(void * start,size_t length,int prot,int flags,int fd,off_t offset)__THROW;
int munmap(void* start,size_t length)__THROW;
//申请一段内存空间，准确将文件直接映射到其中，后面是对应的释放函数
ssize_t splice(int fd_in, loff_t* off_in,int fd_out,loff_t* off_out,size_t len, unsigned int flags);
//用于两个文件描述符之间移动数据
ssize_t tee(int fd_in,int fd_out,size_t len, unsigned int flags);
//两个管道文件描述符之间复制数据，零拷贝操作



int main()
{

}