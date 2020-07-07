#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n--){
        int m;
        cin>>m;
        vector<int> vis(4*m,0);
        int i=m,ans=1;
        while(!vis[i]){
            vis[i++]=1;ans++;
            i=(i+m)%(4*m);
        }
        cout<<ans<<endl;
    }
    return 0;
}