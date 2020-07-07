//
// Created by liu on 19-10-8.
//

//#include <bits/stdc++.h>
//using namespace std;
//
//int main()
//{
//    int N;
//    cin>>N;
//    vector<int> temp(N,0);
//    for(int i=0;i<N;i++)
//        cin>>temp[i];
//    int i=0,j=1,res=1;
//    while(i<N && j<N){
//        if(temp[j]>temp[j-1]){
//            if(j-i+1>res)   res=j-i+1;
//            j++;
//        }
//        else{
//            i=j;
//            j++;
//        }
//    }
//    cout<<res;
//    return 0;
//}