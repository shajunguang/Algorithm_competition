//
// Created by liu on 19-10-12.
//

//#include <bits/stdc++.h>
//using namespace std;
//int game[5][5]={{0,-1,1,1,-1},
//                {1,0,-1,1,-1},
//                {-1,1,0,-1,1},
//                {-1,-1,1,0,1},
//                {1,1,-1,-1,0}};
//const int MAXN=205;
//int a[MAXN],b[MAXN]; //周期性出拳
//
//int main(){
//    int N,NA,NB,resa=0,resb=0;
//    cin>>N>>NA>>NB;
//    for(int i=0;i<NA;i++)
//        cin>>a[i];
//    for(int i=0;i<NB;i++)
//        cin>>b[i];
//    for(int i=0;i<N;i++)
//    {
//        if(game[a[i%NA]][b[i%NB]]==1) resa++;
//        if(game[b[i%NB]][a[i%NA]]==1) resb++;
//    }
//    cout<<resa<<" "<<resb;
//    return 0;
//}
