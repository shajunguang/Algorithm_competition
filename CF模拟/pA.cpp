#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,ans=0,cnt=0,a;
    cin>>n>>k;
    for(int i=1;i<=k;i++){
        cin>>a;
        if(a>0) ans++;
    }
    for(int i=k+1,b;i<=n;i++){
        cin>>b;
        if(a && b==a) ans++;
    }
    cout<<ans<<endl;
    return 0;
}