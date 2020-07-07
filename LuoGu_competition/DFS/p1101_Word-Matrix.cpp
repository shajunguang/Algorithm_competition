//
// Created by liu on 19-10-15.
//

//#include<bits/stdc++.h>
//using namespace std;
//
//const int MAXN=105;
//char mat[MAXN][MAXN],res[MAXN][MAXN];
//const string sp="yizhong";
//int dx[8]={0,-1,-1,-1,0,1,1,1};
//int dy[8]={-1,-1,0,1,1,1,0,-1};
//int n;
//
//bool dfs(int si,int sj,int di,int dj,int u)
//{
//    if(u==sp.size())    return true;
//    if( si>=0 && si<=n && sj>=0 && sj<=n && mat[si][sj]==sp[u])
//        dfs(si+di,sj+dj,di,dj,u+1);
//    else  return false;
//}
//
//int main()
//{
//    cin>>n;
//    for(int i=0;i<n;i++)
//        for(int j=0;j<n;j++)
//        {
//            cin>>mat[i][j];
//            res[i][j]='*';
//        }
//    for(int i=0;i<n;i++)
//        for(int j=0;j<n;j++)
//            if(mat[i][j]==sp[0])
//            {
//                for(int k=0;k<8;k++)
//                    if(i+dx[k]>=0 && i+dx[k]<=n-1 && j+dy[k]>=0 && j+dy[k]<=n && mat[i+dx[k]][j+dy[k]]==sp[1])
//                        if(dfs(i,j,dx[k],dy[k],0))
//                        {
//                            for(int ii=0;ii<sp.size();ii++)
//                                res[i+ii*dx[k]][j+ii*dy[k]]=sp[ii];
//                        }
//            }
//    for(int i=0;i<n;i++)
//    {
//        if(i)   cout<<endl;
//        for(int j=0;j<n;j++)
//            cout<<res[i][j];
//    }
//    return 0;
//}