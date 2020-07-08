/*
 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 思路中心扩展，小心扩展的两种情况，bab或者bb O(n^2) O(1)
 还有个动态规划 dp[i][j]=dp[i+1][j-1]&&s[i]==s[j]
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        string ans;
        for (int l = 0; l < n; ++l) {
            for (int i = 0; i + l < n; ++i) {
                int j = i + l;
                if (l == 0) {
                    dp[i][j] = 1;
                }
                else if (l == 1) {
                    dp[i][j] = (s[i] == s[j]);
                }
                else {
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }
                if (dp[i][j] && l + 1 > ans.size()) {
                    ans = s.substr(i, l + 1);
                }
            }
        }
        return ans;
    }
};
class Solution_1 {
public:
    string longestPalindrome(string s) {
        //中心扩展
        string res;
        for(int k=0;k<(int)s.size();k++){
            for(int i=k,j=k;i>=0&&j<(int)s.size()&&s[i]==s[j];i--,j++)
                if(res.size()<j-i+1) res=s.substr(i,j-i+1);
            for(int i=k,j=k+1;i>=0&&j<(int)s.size()&&s[i]==s[j];i--,j++)
                if(res.size()<j-i+1) res=s.substr(i,j-i+1);
        }
        return res;
    }
};
