#include<syslog.h>
#include<unistd.h>
#include<sys/resource.h>
//日志
void syslog(int priority,const char* message,...); //...表示可变参数
//用户与rsyslogd守护进程通信
void openlog(const char* ident,int logopt,int facility);
//修改syslog的默认输出方式
int setlogmask(int maskpri)__THROW; //设置日志掩码，进行保留和忽略
//用户
uid_t getuid()__THROW;
uid_t geteuid()__THROW;//每个用户存在uid和euid，进程的拥有uid和euid,euid方便资源访问，拥有权限
pid_t getpgid(pid_t pid)__THROW; //进程组的ID
//会话
pid_t setsid(void)__THROW;//创建一个会话
//资源限制
int getrlimit(int resource, struct rlimit* rlim)__THROW;
int setrlimit(int resource, struct rlimit* rlim)__THROW;

int main()
{

}