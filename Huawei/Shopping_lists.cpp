#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e4;
int dp[MAXN];
struct thing{
    int v;
    int im;
    int q;
}nums[65];
bool cmp(const struct thing &a,const struct thing &b){
    return a.im>b.im;
}
int main()
{
    int N,m;
    cin>>N>>m;
    for(int i=1;i<=m;i++){
        int p;
        cin>>nums[i].v>>p>>nums[i].q;
        nums[i].im=nums[i].v*p;
        if(nums[i].q) nums[i].v+=nums[nums[i].q].v,nums[i].im+=nums[nums[i].q].im;
    }
    //sort(nums+1,nums+m+1,cmp);
    for(int i=1;i<=m;i++)
        for(int j=N;j>=nums[i].v;j--)
            dp[j]=max(dp[j],dp[j-nums[i].v]+nums[i].im);
    cout<<dp[N]<<endl;
    return 0;
}