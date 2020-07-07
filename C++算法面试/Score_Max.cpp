//dp[i][j] 前i个数中剩余回合数为j得到的最大分数
//dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]+a[j])
//((()))


/*
#include<bits/stdc++.h>
using namespace std;
const int MAXN=505;
map<int,int> h;
int n,ans=0;
string s;


int main()
{
    cin>>n>>s;
    stack<int> st;
    for(int i=0;i<n;i++) {
        if (s[i] == '(') st.push(i);
        else{
           h[st.top()]=i;
           st.pop();
        }
    }

    return 0;
}
*/