#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        vector<int> nums(n+1,0),dp(n+1,0);
        for(int i=1;i<=n;i++) cin>>nums[i];
        sort(nums.begin(),nums.end());
        dp[1]=nums[1];
        dp[2]=nums[2];
        if(n>2) dp[3]=nums[3];
        for(int i=4;i<=n;i++){
            dp[i]=min(dp[i-1]+nums[2]+nums[i],dp[i-2]+nums[2]+nums[i]+2*nums[3]);
            dp[i]=min(dp[i],dp[i-3]+nums[2]+nums[i]+2*nums[4]);
        }

        cout<<dp[n]<<endl;
    }

    return 0;
}