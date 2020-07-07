#include<bits/stdc++.h>
using namespace std;
#define MEM_B(x) (*((char*)(x))) //求指定地址的一个字节或字
#define MEM_W(x) (*((int*)(x)))
#define SUB(x,y) (x-y)
#define UPCASE(c) (((c)>='a'&&(c)<='z')?((c)-0x20):(c)) //小写转大写
#define INC_SAT(val) (val=((val)+1>(val))?(val)+1:(val)) //防止溢出
#define ARR_SIZE( a ) ( sizeof( (a) ) / sizeof( (a[0]) ) ) //数组个数

int main()
{
    int bTest=0x123456;
    char m=MEM_B((&bTest));
    int n=MEM_W((&bTest));
    printf("0x%x 0x%x\n",m,n);
    int ans=SUB(3,4);
    cout<<ans<<endl;
    cout<<(char)UPCASE('g')<<endl;
    int val=INT_MAX;
    INC_SAT(val);
    cout<<val<<endl;
    int a[]={1,2,3,4,5};
    cout<<ARR_SIZE(a)<<endl;
}