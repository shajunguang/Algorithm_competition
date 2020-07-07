//
// Created by liu on 19-10-12.
//

//#include <bits/stdc++.h>
//using namespace std;
//const int MAXN=1005;
//int vis[MAXN];
//
//int main()
//{
//    memset(vis,0,sizeof vis);
//    int M,N,word,len=0,res=0;
//    queue<int> qu;
//    cin>>M>>N;
//    while(N--){
//        cin>>word;
//        if(vis[word]) continue;
//        if(!vis[word]){
//            if(len<M){
//                vis[word]=1;
//                qu.push(word);
//                len++;
//                res++;
//            }
//            else{
//                vis[word]=1;
//                vis[qu.front()]=0;
//                qu.pop();
//                qu.push(word);
//                res++;
//            }
//        }
//    }
//    cout<<res;
//    return 0;
//}