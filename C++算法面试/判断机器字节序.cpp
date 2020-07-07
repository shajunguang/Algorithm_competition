#include<bits/stdc++.h>
#include <netinet/in.h>
#include<bits/socket.h>

#define com(A,B) ((A)*(B))

using namespace std;
void byteorder()
{
    union
    {
        short value;
        char union_bytes[sizeof(short)]; //利用共同体共享一个内存概念
    }test;
    test.value = 0x0102;
    if((test.union_bytes[0]==1) &&(test.union_bytes[1]==2))
        printf("big endian\n");
    else if(test.union_bytes[0]==2&&test.union_bytes[1]==1)
        printf("little endian\n");
    else
        printf("unknown...\n");
}
int main()
{
    byteorder();
    int x=0x10010102;
    char c=x;
    printf("0x%x\n",c); //pc端都是小端字节序
    cout<<setbase(16)<<htonl(0x0110102)<<endl; //注意这里是一个字节一个字节调换顺序
    //所以变成了0x02011100->2011100
    int i=5;
    int ans=com(3,2);
    cout<<ans<<endl;
    cout<<(int)'i'<<endl;
    return 0;
}