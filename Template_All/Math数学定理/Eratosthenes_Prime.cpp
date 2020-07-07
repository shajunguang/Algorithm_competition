#include<bits/stdc++.h>
int vis[10000];
//筛选小于n的质数
void Prime(int n){
    int m=sqrt(n+0.5);
    memset(vis,0,sizeof vis);
    for(int i=2;i<=m;i++)if(!vis[i])
        for(int j=i*i;j<=n;j+=i) vis[j]=1;
}