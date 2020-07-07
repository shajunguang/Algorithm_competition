//
// Created by liu on 19-10-15.
//

//#include <bits/stdc++.h>
//using namespace std;
//
//int vis[10][10],N,M,FX,FY,ans=0;
//int dx[4]={0,-1,0,1};
//int dy[4]={-1,0,1,0};
//
//void dfs(int si,int sj)
//{
//    if(si==FX && sj==FY)
//    {
//        ans++;
//        return;
//    }
//    for(int i=0;i<4;i++)
//        if(si+dx[i]>=1 && si+dx[i]<=N && sj+dy[i]>=1 && sj+dy[i]<=M && !vis[si+dx[i]][sj+dy[i]])
//        {
//            vis[si][sj]=1;
//            dfs(si+dx[i],sj+dy[i]);
//            vis[si][sj]=0;
//        }
//}
//
//int main()
//{
//    int T,SX,SY,TX,TY;
//    cin>>N>>M>>T>>SX>>SY>>FX>>FY;
//    memset(vis,0,sizeof vis);
//    for(int i=0;i<T;i++)
//    {
//        cin>>TX>>TY;
//        vis[TX][TY]=1;
//    }
//    dfs(SX,SY);
//    cout<<ans;
//    return 0;
//}