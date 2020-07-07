//
// Created by liu on 19-8-18.
//

//#include <cstdio>
//#include <queue>
//#include <map>
//#define local
//using namespace std;
//
//const int maxt = 1000+10;
//
//int main()
//{
//#ifdef local
//    freopen("in.txt","r",stdin);
//    //freopen("out.txt","w",stdout);
//#endif
//    int t, kase = 0;
//    while(scanf("%d", &t)==1 && t){
//        printf("Scenario #%d\n", ++kase);
//
//        //记录所有人的团队编号
//        map<int, int> team;  //team[x]表示x的人所在团队编号
//        for(int i=0;i<t;i++){
//            int n,x;
//            scanf("%d",&n);
//            while(n--)  { scanf("%d", &x); team[x]=i; }
//        }
//
//    //模拟
//    queue<int> q, q2[maxt];
//        for(;;){
//            int x;
//            char cmd[10];
//            scanf("%s", cmd);
//            if(cmd[0]=='S') break;
//            else if(cmd[0]=='D'){
//                int t = q.front();
//                printf("%d\n",q2[t].front());q2[t].pop();
//                if(q2[t].empty())   q.pop();  // 团队t全体出队列
//            }
//            else if(cmd[0]=='E'){
//                scanf("%d", &x);
//                int t = team[x];
//                if(q2[t].empty())   q.push(t);  // 团队t进入队列
//                q2[t].push(x);
//            }
//        }
//        printf("\n");
//    }
//
//    return 0;
//}