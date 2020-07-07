#include<bits/stdc++.h>
using namespace std;
const int mod=1e5+3;
int f[mod];
int main()
{
    int n,k;
    cin>>n>>k;
    if(k==1) { cout<<"1";return 0; }
    f[1]=1;f[2]=2;
    for(int i=3;i<=k;i++){
        f[i]=1;
        int j=i;while(j>0) j--,f[i]+=f[j];
        f[i]%=mod;
    }
    for(int i=k+1;i<=n;i++)
        for(int j=1;j<=k;j++){
            f[i]+=f[i-j];
            f[i]%=mod;
        }
    cout<<f[n];
    return 0;
}