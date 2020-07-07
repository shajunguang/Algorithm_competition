//
// Created by liu on 19-8-16.
//

//#include <cstdio>
//#include <cstdlib>
//#include <string>
//#include <vector>
//#include <iostream>
//#define local
//
//using namespace std;
//
//const int maxn = 30;
//int n;
//vector<int> pile[maxn];
//
//// 找木块a所在的pile和height,以引用的形式返回调用者
//void find_block(int a, int& p, int& h){
//    for(p =0;p<n;p++)
//        for(h=0;h<pile[p].size();h++)
//            if(pile[p][h] == a) return;
//}
//
//// 把第p堆高度为h的木块上方的所有木块移回原位
//void clear_above(int p, int h){
//    for(int i=0;i<pile[p].size();i++){
//        int b = pile[p][i];
//        pile[b].push_back(b);
//    }
//    pile[p].resize(h+1);
//}
//
//// 把第p堆高度为h及其上方的木块整体移动到p2堆的顶部
//void pile_onto(int p, int h, int p2){
//    for(int i=0;i<pile[p].size();i++)
//        pile[p2].push_back(pile[p][i]);
//    pile[p].resize(h);
//}
//
//void print(){
//    for(int i=0;i<n;i++){
//        printf("%d", i);
//        for(int j =0;j<pile[i].size();j++)  printf(" %d",pile[i][j]);
//        printf("\n");
//    }
//}
//
//int main()
//{
//#ifdef local
//    freopen("in.txt","r",stdin);
//    //freopen("out.txt","w",stdout);
//#endif
//    int a,b;
//    cin>>n;
//    string s1, s2;
//    for(int i=0;i<n;i++)    pile[i].push_back(i);
//    while(cin>>s1>>a>>s2>>b && s1 != "quit"){
//        int pa, pb, ha, hb;
//        find_block(a,pa,ha);
//        find_block(b,pb,hb);
//        if(pa==pb) continue;
//        if(s2=="onto")  clear_above(pb, hb);
//        if(s1 == "move")    clear_above(pa,ha);
//        pile_onto(pa,ha,pb);
//    }
//    print();
//    return 0;
//}