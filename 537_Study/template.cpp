//猿辅导第二题最大子树
#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int MAXN=1e5+10;
const int MODN=1e9+3;
vector<vector<int>> gra(MAXN);
vector<int> val(MAXN);
vector<int> dp(MAXN,-1);
int dfs(int u){//最大子树
    
    if(dp[u]!=-1)return dp[u];
    dp[u] = val[u];
    // dp[u] = (dp[u]+MODN)%MODN;
    // cerr<<"poi "<<u<<endl;
    for(int i=0;i<gra[u].size();i++){
        int nx=gra[u][i];
        int ret=dfs(nx);
        // cerr<<nx<<" "<<ret<<endl;
        if(ret>0)dp[u]+=ret;
        // dp[u] = (dp[u]+MODN)%MODN;
    }
    return dp[u];
}
int32_t main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        if(b-2>=0 && b-2!=i )
        gra[b-2].emplace_back(i);
        val[i]=a;
    }
    int ans=-1e18;
    for(int i=0;i<n;i++){
        // cerr<<"times "<<i<<endl;
        ans = max(ans,dfs(i));
    }
    ans = (ans + MODN)%MODN;
    cout<<ans<<endl;
    return 0;
}