#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--){
        int n,k,sum=0,j=-1,f=1,ans=-1;
        cin>>n>>k;
        for(int i=0;i<n;i++){
            int m;cin>>m;
            sum+=m%k;
            if(sum%k!=0) {
                if(f) j=i,f=0;
                ans=max(ans,i+1);
            }
            else if(j!=-1) ans=max(ans,i-j);
        }
        cout<<ans<<endl;
    }
    return 0;
}