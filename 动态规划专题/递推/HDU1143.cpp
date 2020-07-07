//3*n矩阵放满1*2,不同于2*n,这里一维解决不了
//dp[i][j]表示方块数3*i+j的方案数(j表示多出的部分,0,1,2)
#include<bits/stdc++.h>
using namespace std;
long long f[31][3];

int main()
{
    int n;
    f[0][0]=f[1][1]=f[0][2]=1;
    for(int i=2;i<31;i++){
        f[i][0]=f[i-2][0]+f[i-1][1]+f[i-2][2];
        f[i][1]=f[i-1][2];
        f[i][2]=f[i][0]+f[i-1][1];
    }
    while(cin>>n && n!=-1){
        cout<<f[n][0]<<endl;
    }

    return 0;
}