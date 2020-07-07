#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>

#define p 8//要压的位数
#define carry 100000000//相应的10的P次方 用于进位
//这样如果要改变压位的位数只要改这里就可以
using namespace std;

const int Maxn=50001;

char s1[Maxn],s2[Maxn];
int a[Maxn],b[Maxn],ans[Maxn];

int change(char s[],int n[])//压位的核心部分
{
    char temp[Maxn];//中间变量 记录每p位的数
    int len=strlen(s+1),cur=0;
    while(len/p){//如果len大于等于p
        strncpy(temp,s+len-p+1,p);//从后面截出来p位数
        n[++cur]=atoi(temp);//把temp搞成数字
        len-=p;//继续下p位
    }
    if(len){//如果最后len不是正好p的倍数 也就是还剩下点不够p位的
        memset(temp,0,sizeof(temp));
        strncpy(temp,s+1,len);//全截下来
        n[++cur]=atoi(temp);//赋上
    }
    return cur;//返回一个位数
}
//这里就是(二)中的内容了 计算正常计算就行
int add(int a[],int b[],int c[],int l1,int l2)
{
    int x=0,l3=max(l1,l2);
    for(int i=1;i<=l3;i++){
        c[i]=a[i]+b[i]+x;
        x=c[i]/carry;//进位
        c[i]%=carry;
    }
    while(x>0){c[++l3]=x%10;x/=10;}
    return l3;//返回答案的位数
}

void print(int a[],int len)
{
    printf("%d",a[len]);//处理高位
    for(int i=len-1;i>=1;i--)printf("%0*d",p,a[i]);//输出p位 不足补0
    printf("\n");
}

int main()
{
//	freopen("t.in","r",stdin);
//	freopen("t.out","w",stdout);
    scanf("%s%s",s1+1,s2+1);//读入两个字符串

    int la=change(s1,a);//将s1这个字符串转化为a这个整型数组
    int lb=change(s2,b);//同上

    int len=add(a,b,ans,la,lb);
    //计算长度为la的a数组和长度为lb的b数组最后把答案赋给ans数组 并顺便计算出ans的长度(便于输出)
    print(ans,len);//输出函数
    return 0;
}
