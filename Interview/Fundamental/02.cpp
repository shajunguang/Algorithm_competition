#include<bits/stdc++.h>
using namespace std;
int func(int x){
    int count=0;
    while(x){
        count++;
        x=x&(x-1); //这个循环可以求x的1的个数,不管x是否是负数
    }
    return count;
}
int main()
{
    cout<<func(9999); //二进制位10011100001111
    return 0;
}
