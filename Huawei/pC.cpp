#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e4+5;
string s[MAXN],s1[MAXN];
int minDistance(string st1,string st2){
    int n1=st1.size();
    int n2=st2.size();
    vector<vector<int>> dp(n1+1, vector<int>(n2+1,0));

    for(int i=0;i<=n1;i++)dp[i][0]=i;
    for(int i=0;i<=n2;i++)dp[0][i]=i;

    for(int i=1;i<=n1;i++)
        for(int j=1;j<=n2;j++){
            if(st1[i-1]==st2[j-1]) dp[i][j]=dp[i-1][j-1];
            else dp[i][j]=1+min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
        }
    return dp[n1][n2];
}


int main()
{
    int N;
    cin>>N;
    for(int i=0;i<N;i++) cin>>s[i];
    for(int i=0;i<N;i++) cin>>s1[i];

    long long ans=0;
    for(int i=0;i<N;i++)
        ans+=minDistance(s[i],s1[i]);
    cout<<ans<<endl;
    return 0;
}