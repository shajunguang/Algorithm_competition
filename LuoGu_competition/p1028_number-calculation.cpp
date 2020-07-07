//
// Created by liu on 19-10-9.
//

//#include <bits/stdc++.h>
//using namespace std;

///*
//int res=1;
//void dfs(int n){  //如果这样写其实很多地方其实重新计算了.
//    if(n/2==0)    return;
//    for(int i=1;i<=n/2;i++){
//        res++;
//        dfs(i);
//    }
//}
// */
//const int MAXN=1005;
//long long res[MAXN];
//
//void dfs(int n){
//    if(res[n]) return;
//    for(int i=1;i<=n/2;i++){
//        dfs(i);
//        res[n] += res[i];
//    }
//    res[n]++;
//}
//
//int main()
//{
//    int n;
//    cin>>n;
//    memset(res,0,sizeof res);
//    res[1]=1;
//    dfs(n);
//    cout<<res[n];
//    return 0;
//}