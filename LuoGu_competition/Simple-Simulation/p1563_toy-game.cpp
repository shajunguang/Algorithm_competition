//
// Created by liu on 19-10-13.
//

//#include <bits/stdc++.h>
//using namespace std;
//
//const int MAXN=100005;
//string s[MAXN]; //存取玩游戏的小人
//map<string,int> direct;  //存取玩游戏的朝向
//
//int main(){
//    int n,m,fx; //n为游戏人数,m为操作指令,fx为朝向
//    cin>>n>>m;
//    for(int i=0;i<n;i++){
//        cin>>fx>>s[i];
//        direct[s[i]]=fx;
//    }
//    int res=0,lr,mv;  //res游戏起始位置,lr为移动方向(0-左，1-右),mv为移动步数
//    while(m--){
//        cin>>lr>>mv;
//        if(direct[s[res]])  res = lr?(n-mv+res)%n:(mv+res)%n;
//        else    res = lr?(mv+res)%n:(n-mv+res)%n;
//    }
//    cout<<s[res];
//    return 0;
//}