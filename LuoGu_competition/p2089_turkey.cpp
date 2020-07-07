//
// Created by liu on 19-10-10.
//

//#include <bits/stdc++.h>
//using namespace std;
//
//vector<int> num_s[1000];
//int num[10],res=0;
//
//void dfs(int n){
//    if(n==0){
//        for(int i : num)
//            num_s[res].push_back(i);
//        res++;
//        if(res>10){
//            for(int i=0;i<res-1;i++)
//            {
//                int flag=0;
//                for(int j=0;j<10;j++)
//                    if(num_s[i][j]!=num[j]){
//                        flag=1;
//                        break;
//                    }
//                if(!flag)
//                {
//                    res--;
//                    num_s[res].clear();
//                    break;
//                }
//            }
//        }
//        return;
//    }
//    for(int i=9;i>=0;i--){
//        if(num[i]==3)
//            continue;
//        num[i]++;
//        dfs(n-1);
//        num[i]--;
//    }
//}
//
//int main()
//{
//    int n;
//    cin>>n;
//    if(n<10 || n>30)    cout<<"0";
//    else{
//        for(int & i : num)
//              i=1;
//        dfs(n-10);
//        cout<<res<<endl;
//        for(int i=0;i<res;i++)
//        {
//            for(int j=0;j<10;j++)
//            {
//                if(j)   cout<<" ";
//                cout<<num_s[i][j];
//            }
//            cout<<endl;
//        }
//    }
//    return 0;
//}

//大佬解法
//#include<cctype>
//#include<cstdio>
//
//using namespace std;
//
//const int maxn = 13;
//
//char ans[1000000 + 5];
//char *anscur = ans;
//int nums[maxn];                    // 当前调料
//int cnt = 0;                    // 方案数
//
//void printans(){
//    int offset;
//    for(int i = 0; i < 10; i++){
//        sprintf(anscur, "%d %n", nums[i], &offset);
//        anscur += offset;
//    }
//    sprintf(anscur, "\n%n", &offset);
//    anscur += offset;
//}
//
//void dfs(int cur, int left){    // 深搜过程
//    if(cur == 10 && !left){        // 已经搜到第10层，这个时候调料恰好加完
//        cnt++;                    // 方案数+1
//        printans();                // 将方案输出到字符串里面
//        return;
//    }
//    int &i = nums[cur];            // 声明别名（引用）
//    for(i = 1; i <= 3; i++){
//        if((10 - cur - 1) * 3 + i < left) continue;    // 剪枝。如果剩下的调料都加3克都不够，说明不可能
//        if((10 - cur - 1) + i > left) break;        // 剪枝。如果剩下的调料都加一克也超量，说明不可能
//        dfs(cur + 1, left - i);
//    }
//}
//
//int main(){
//    int n;
//    scanf("%d", &n);
//
//    if(10 <= n && n <= 30) dfs(0, n);// 如果n不在[10, 30]范围内，说明不可能有解，跳过搜索
//    printf("%d\n%s", cnt, ans);        //输出答案
//}