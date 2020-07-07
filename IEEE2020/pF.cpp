#include<bits/stdc++.h>
using namespace std;
const int N=55;
int p[N];
typedef long long ll;
ll d[N];
int n;
int ans=INT_MAX;
bool vis[N];
void dfs(int cnt,ll health,int pay)
{
    if(pay>=ans)return;
    if(cnt>=n)
    {
        ans=min(ans,pay);
        return;
    }
    if(!vis[cnt])
    {
        vis[cnt]=true;
        dfs(cnt+1,health+d[cnt],pay+p[cnt]);
        vis[cnt]=false;
    }
    if(health>=d[cnt])
        dfs(cnt+1,health,pay);

}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)cin>>d[i];
    for(int i=0;i<n;i++)cin>>p[i];
    dfs(0,0,0);
    cout<<ans;
    return 0;

}