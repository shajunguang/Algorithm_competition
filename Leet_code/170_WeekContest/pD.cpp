//dp[a][b]=min(dp[a+1][b]+1,dp[a][b-1]+1,dp[a+1][b-1](s[a]==s[b]))
//最长回文子序列,找到最长的子序列，序列长度相减就是最小插入个数
#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int minInsertions(string s) {
        vector<vector<int>>dp(s.size(), vector<int>(s.size(), 0));
        for(int i=s.size()-1;i>=0;i--){
            dp[i][i]=1; //一个字符本身就是回文
            for(int j=i+1;j<s.size();j++){
                if(s[i]==s[j]) dp[i][j]=dp[i+1][j-1]+2;
                else dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }
        }
        return s.size()-dp[0].back();
    }
};