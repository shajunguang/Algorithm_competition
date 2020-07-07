//2*n放满1*2的木块,f[i]=f[i-1]+f[i-2]
#include<bits/stdc++.h>
using namespace std;
long long f[51];

int main()
{
    int n;
    f[1]=1;
    f[2]=2;
    for(int i=3;i<51;i++)f[i]=f[i-1]+f[i-2];
    while(cin>>n){
        cout<<f[n]<<endl;
    }
    return 0;
}
