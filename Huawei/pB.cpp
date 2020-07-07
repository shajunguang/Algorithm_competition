#include<bits/stdc++.h>
using namespace std;
int nums[12]={1,1,2,6,24,120,720,5040,40320,362880,3628800,39916800};
int k,n;
int vis[12],pos[12];
void dfs(int p,int cur){
    if(cur==k-1){
        string ans;
        int l=0;
        for(int i=0;i<n+1;i++) if(vis[i]) pos[l++]=i;
        for(int i=0;i<k-1;i++){
            if(i==0) for(int j=0;j<pos[0];j++) ans+="*";
            else for(int j=pos[i-1];j<pos[i];j++) ans+="*";
            ans+='|';
        }
        for(int j=pos[k-2];j<n;j++) ans+='*';
        cout<<ans<<endl;
        return;
    }
    if(p==n+1) return;

     //另一种思路
     if(!vis[p]){ //选择p这个点
        vis[p]=1;
        dfs(p+1,cur+1);
        vis[p]=0;
     }
     dfs(p+1,cur); //不选择p这个点
     /*
    for(int i=p;i<n+1;i++) //从p到n中选择k个点插入
        if(!vis[i]){
            vis[i]=1;
            dfs(i+1,cur+1); //递归到i+1到n中选择k-cur个
            vis[i]=0;
        }
     */
}
int main()
{
    cin>>n>>k;
    if(n<k) swap(n,k);
    cout<<nums[n+1]/(nums[k-1]*nums[n-k+2])<<endl;
    memset(pos,-1,sizeof pos);
    dfs(0,0);
    return 0;
}