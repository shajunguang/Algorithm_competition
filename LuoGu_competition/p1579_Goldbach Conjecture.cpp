//
// Created by liu on 19-10-10.
//

//#include <bits/stdc++.h>
//using namespace std;
//
//const int MAXN=20005;
//int vis[MAXN];
//
//int main()
//{
//    int n;
//    cin>>n;
//    //不大于n的素数筛选,Eratosthenes筛法板子
//    int m=sqrt(n+0.5);
//    memset(vis,0,sizeof vis);
//    for(int i=2;i<=m;i++)   if(!vis[i])
//        for(int j=i*i;j<=n;j+=i)    vis[j]=1;
//    int flag=0;
//    for(int i=2;i<n;i++){
//        if(!vis[i]) {
//            for(int j=i;j<n-i;j++)
//                if(!vis[j] && !vis[n-i-j])
//                {
//                    flag=1;
//                    cout<<i<<" "<<j<<" "<<n-i-j;
//                    break;
//                }
//            if(flag)    break;
//        }
//    }
//    return 0;
//}