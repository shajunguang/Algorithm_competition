//EOF依次排列O不能相邻
//a[i]表示不以O结尾的,b[i]表示以O结尾的,t[i]=a[i]+b[i]
//a[i]=a[i-1]*2+b[i-1]*2
//b[i]=a[i-1]=2*t[i-2]
//t[i]=a[i-1]*3+b[i-1]*2
//解方程组有t[i]=2*t[i-1]+2*t[i-2]
#include<bits/stdc++.h>
using namespace std;
long long f[41];

int main()
{
    int n;
    f[1]=3;
    f[2]=8;
    for(int i=3;i<41;i++) f[i]=f[i-1]*2+f[i-2]*2;
    while(cin>>n){
        cout<<f[n]<<endl;
    }
    return 0;
}