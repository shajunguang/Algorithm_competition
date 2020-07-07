//
// Created by liu on 19-8-30.
//

//#include <cstdlib>
//#include <cstdio>
//#include <cstring>
//using namespace std;
//
//int row[8],TC,a,b,lineCounter;   // global variables
//
//bool place(int r, int c){
//    for(int prev=0;prev<c;prev++)
//        if(row[prev]==r || (abs(row[prev]-r) == abs(prev-c)))
//            return false;
//    return true;
//}
//
//void backtrack(int c){
//    if(c==8 && row[b]==a){
//        printf("%2d      %d",++lineCounter,row[0]+1);
//        for(int j=1;j<8;j++)    printf(" %d",row[j]+1);
//        printf("\n");
//    }
//    for(int r=0;r<8;r++)
//        if(place(r,c)){
//            row[c]=r;backtrack(c+1);
//        }
//}
//
//int main()
//{
//    scanf("%d",&TC);
//    while(TC--){
//        scanf("%d%d",&a,&b);a--;b--;
//        memset(row, 0, sizeof(row));lineCounter=0;
//        printf("SOLN       COLUMN\n");
//        printf(" #      1 2 3 4 5 6 7 8\n\n");
//        backtrack(0);
//        if(TC)  printf("\n");
//    }
//    return 0;
//}

//另一个版本

//#include <iostream>
//#include <cstdlib>
//#include <cstdio>
//
//using namespace std;
//
//int  ans[92][9],temp[9];
//int  Count = 0;
//void dfs(int L, int M, int R, int d)
//{
//    if (d == 8) {
//        Count ++;
//        return;
//    }
//    for (int i = 0 ; i < 8 ; ++ i) {
//        if (((L|M|R)&(1<<i)) == 0) {
//            for (int j = 0 ; j < d ; ++ j)
//                temp[j] = ans[Count][j];
//            ans[Count][d] = i+1;
//            dfs((L|(1<<i))<<1, M|(1<<i), (R|(1<<i))>>1, d+1);
//            for (int j = 0 ; j < d ; ++ j)
//                ans[Count][j] = temp[j];
//        }
//    }
//}
//
//int main()
//{
//    Count = 0;
//    dfs(0, 0, 0, 0);
//
//    int t,x,y;
//    while (~scanf("%d",&t))
//        while (t --) {
//            scanf("%d%d",&x,&y);
//
//            printf("SOLN       COLUMN\n");
//            printf(" #      1 2 3 4 5 6 7 8\n\n");
//            int count = 1;
//            for (int i = 0 ; i < Count ; ++ i)
//                if (ans[i][y-1] == x) {
//                    printf("%2d     ",count ++);
//                    for (int j = 0 ; j < 8 ; ++ j)
//                        printf(" %d",ans[i][j]);
//                    printf("\n");
//                }
//            if (t) printf("\n");
//        }
//    return 0;
//}
