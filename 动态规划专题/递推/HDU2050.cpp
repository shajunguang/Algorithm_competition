//数学问题,一条折线可以将空间划分为2部分
//对于第n-1条折线，它把空间划分的区域为f(n-1),为了让增加的区域更多，
// 新增的折线要和之前的n-1条折线的2*(n-1)条边都相交，产生4*(n-1)条新的线段（图中黄蓝），
// 每条线段或射线(绿)产生一个新区域，但是折线的头（黄色）的两线段一共只能产生一个区域，
// 所以新增区域的数量为4*(n-1) -1+2 即 4*(n-1) +1 ；
//F[n]=F[n-1]+4(n-1)+1

#include<bits/stdc++.h>
using namespace std;
int f[21];

int main()
{
    int n;
    f[1]=2;
    for(int i=2;i<21;i++) f[i]=f[i-1]+4*(i-1)+1;
    while(cin>>n){
        cout<<f[n]<<endl;
    }

    return 0;
}