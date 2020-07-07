////
//// Created by liu on 19-10-19.
////
//
//#include<bits/stdc++.h>
//using namespace std;
//#define MAXN 100005
//int price[MAXN],mer_pos[MAXN];
//struct NODE{
//    int e;
//    int next; //next[i]表示与第i条边同起点的上一条边的储存位置
//}edge[MAXN];
//int cnt;
//int head[MAXN];
//void add(int u,int v){
//    edge[cnt].e=v;    //edge[i]表示第i条边的终点
//    edge[cnt].next=head[u]; //head[i]表示以i为起点的最后一条边的储存位置
//    head[u]=cnt++;
//}
//int main() {
//    memset(head, -1, sizeof(head));
//    cnt = 0;
//    int n;
//    cin >> n;
//    for(int i=1;i<=n;i++)
//        cin>>price[i];
//    int a, b;
//    for(int i=1;i<n;i++) {
//        cin >> a >> b;
//        add(a, b);
//        add(b, a);
//    }
//    int m;
//    cin>>m;
//    for(int i=0;i<m;i++)
//        cin>>mer_pos[i];
////    int start;
////    cin >> start;
////    for (int i = head[start]; i != -1; i = edge[i].next)
////        cout << start << "->" << edge[i].e << " " << endl;
//
//    return 0;
//}