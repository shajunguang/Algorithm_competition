//
// Created by liu on 19-10-15.
//

//#include <bits/stdc++.h>
//using namespace std;
//
//const int MAXN=25;
//int adj[MAXN][MAXN],vis[MAXN];
//int len=0,len_max=-1,n;
//string s[MAXN];
//
//void dfs(int u)
//{
//    int flag=1;
//    for(int i=0;i<n;i++)
//        if(adj[u][i] && vis[i]<2)
//        {
//            flag=0;
//            break;
//        }
//    if(flag){
//        if(len>len_max) len_max=len;
//        return;
//    }
//    for(int i=0;i<n;i++)
//        if(adj[u][i] && vis[i]<2)
//        {
//            vis[i]++;
//            len += s[i].size()-adj[u][i];
//            dfs(i);
//            vis[i]--;
//            len -= s[i].size()-adj[u][i];
//        }
//}
//
//int main()
//{
//    cin>>n;
//    for(int i=0;i<n;i++)
//        cin>>s[i];
//    char c;
//    cin>>c;
//    memset(adj,0,sizeof adj);
//    memset(vis,0,sizeof vis);
//    for(int i=0;i<n;i++){
//        int s_len=s[i].size();
//        for(int j=0;j<n;j++)
//            for(int ii=s_len-1;ii>0;ii--)
//            {
//                string temp1=s[i].substr(ii),temp2;
//                if(s_len-ii<s[j].size()){
//                    temp2=s[j].substr(0,s_len-ii);
//                    //这个地方题目出的太sadiao了,为了使龙更长,竟然可以只重合最短的长度，因此这儿要跳出去。
//                    if(temp1==temp2)    { adj[i][j]=s_len-ii;break;}
//                }
//            }
//    }
//    for(int i=0;i<n;i++) {
//        len=0;
//        memset(vis,0,sizeof vis);
//        if(s[i][0]==c)
//        {
//            len += s[i].size();
//            vis[i]++;
//            dfs(i);
//        }
//    }
//    cout<<len_max;
//    return 0;
//}