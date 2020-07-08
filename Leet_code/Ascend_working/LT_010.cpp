/*
 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
 dp方法：从集合角度来思考，降低分析难度，如何匹配，计算最大值，最小值等和dp相关
 1.状态表示
 1>f[i,j]集合，所有s[1,i]和p[1,j]的匹配共集
 2>属性 bool是否合理
 2.状态计算
 1>p[j]!='*' s[i]==p[i] || p[j]=='.' ||f[i-1,j-1]
 2>p[j]=='*' 需要枚举*前面的字母要出现几次,可优化为f[i,j-2]||f[i-1,j]&&s[i]==p[j] 匹配0个或任意个
 O(n^3)可优化，*需要枚举
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size(), m=p.size();
        s = ' '+ s, p= ' ' + p;
        vector<vector<bool>> f(n+1, vector<bool>(m+1));
        for(int i=0;i<=n;i++)
            for(int j=0;j<=m;j++)
                if(!i && !j)    f[i][j]=true;
                else
                {
                    if(j+1<=m && p[j+1]=='*')   continue;
                    if(p[j]!='*')
                    {
                        if(p[j]=='.' || s[i]==p[j])
                            if(i>0 && j>0)
                                f[i][j]=f[i-1][j-1];
                    }
                    else
                    {
                        if(j>=2)    f[i][j]=f[i][j-2];
                        if(i>0 && j>0)
                        {
                            if(p[j-1]=='.' || s[i]==p[j-1])
                                if(f[i-1][j])
                                    f[i][j]=true;
                        }
                    }
                }
        return f[n][m];
    }
};
//另一个版本
class Solution_1 {
public:
    bool isMatch(string s, string p) {
        int m=s.size(),n=p.size();
        vector<vector<bool>>dp(m+1,vector<bool>(n+1,false));
        s=' '+s,p=' '+p;
        dp[0][0]=true;
        for(int i=0;i<=m;i++)
            for(int j=1;j<=n;j++){
                if(j+1<=n && p[j+1]=='*') continue;
                if(i && p[j]!='*')
                    dp[i][j]=dp[i-1][j-1]&&(s[i]==p[j] || p[j]=='.');
                else if(p[j]=='*'){
                    dp[i][j]=j>1 && dp[i][j-2];
                    dp[i][j]=dp[i][j]||i && dp[i-1][j] && (s[i]==p[j-1]||p[j-1]=='.');
                }
            }

        return dp[m][n];
    }
};