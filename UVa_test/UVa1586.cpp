////
//// Created by liu on 19-6-24.
////
//#include <bits/stdc++.h>
//#define maxn 256
//#define _for(i,a,b) for(int i=(a);i<(b);++i)
//typedef long long ll;
//using namespace std;
//
//int main(){
//    unordered_map<char,double>um{{'C',12.01},{'H',1.008},{'O',16.0},{'N',14.01}};
//    //for(auto x:um) cout<<x.first<<" : "<<x.second<<endl;
//    int N;
//    char s;
//    scanf("%d\n",&N);
//    char buf[maxn];//buf是英文buffer的缩写，意思是缓冲区， 它本质上就是一段存储数据的内存。
//    while(N--){
//        int cnt = -1;//用来维护当前已经输入的数字cnt，cnt=-1表示该字母还未开始计数
//        double ans = 0.0;
//        s = 0;
//        scanf("%s",buf);
//        _for(i,0,strlen(buf)){
//            char c = buf[i];
//            if(isupper(c)){//是否为大写英文字母
//                if(i){
//                    if(cnt==-1) cnt = 1;
//                    ans+=um[s]*cnt;//把之前的大写字母（带着他的数字）先加上
//                }
//                s = c;//加上之后s更新为当前的大写字母
//                cnt = -1;
//            }
//            else{
//                assert(isdigit(c));
//                if(cnt==-1) cnt = 0;
//                cnt = cnt*10+c-'0';
//            }
//        }
//        if(cnt==-1) cnt = 1;
//        ans+=um[s]*cnt;
//        printf("%.3lf\n",ans);
//    }
//    return 0;
//}
