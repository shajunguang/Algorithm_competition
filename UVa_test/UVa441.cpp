//
// Created by liu on 19-8-29.
//

//#include <iostream>
//using namespace std;
//
//int main()
//{
//    int S[15];
//    int k,kase=0;
//    while(cin>>k && k){
//        if(kase)    printf("\n"); else kase++;
//        for(int i=0;i<k;i++)    cin>>S[i];
//        for(int a=0;a<k-5;a++)
//            for(int b=a+1;b<k-4;b++)
//                for(int c=b+1;c<k-3;c++)
//                    for(int d=c+1;d<k-2;d++)
//                        for(int e=d+1;e<k-1;e++)
//                            for(int f=e+1;f<k;f++)
//                                printf("%d %d %d %d %d %d\n",S[a],S[b],S[c],S[d],S[e],S[f]);
//    }
//}

//另一个答案
//#include <iostream>
//#include <cstdlib>
//#include <cstdio>
//
//using namespace std;
//
//int numb[50];
//int used[50];
//int save[50];
//
//void dfs( int d, int s, int n )
//{
//    if ( d == 6 ) {
//        printf("%d",save[0]);
//        for ( int i = 1 ; i < 6 ; ++ i )
//            printf(" %d",save[i]);
//        printf("\n");
//        return;
//    }
//    for ( int i = s ; i < n ; ++ i )
//        if ( !used[i] ) {
//            used[i] = 1;
//            save[d] = numb[i];
//            dfs( d+1, i+1, n );
//            used[i] = 0;
//        }
//}
//
//int main()
//{
//    int n,t = 0;
//    while ( cin >> n && n ) {
//        if ( t ++ ) printf("\n");
//        for ( int i = 0 ; i < n ; ++ i ) {
//            cin >> numb[i];
//            used[i] = 0;
//        }
//        dfs( 0, 0, n );
//    }
//
//    return 0;
//}
