//
// Created by liu on 19-10-9.
//

//#include <bits/stdc++.h>
//using namespace std;
//const int MAXN=400;
//char pos[MAXN][26];
//int num[26];
//
//int main()
//{
//    string s;
//    for(int i=0;i<4;i++){
//        getline(cin,s);
//        for(auto c: s)
//            if(c>='A' && c<='Z')
//                num[c-'A']++;
//        s.clear();
//    }
//    int max=INT_MIN;
//    for(auto i:num)
//        if(i>=max)  max=i;
//    pos[max][0]='A';
//    for(int i=1;i<26;i++)
//        pos[max][i]=pos[max][0]+i;
//    for(int i=max-1;i>=0;i--)
//        for(int j=0;j<26;j++){
//            if(num[j]+i-max>=0) pos[i][j]='*';
//            else pos[i][j]=' ';
//        }
//    for(int i=0;i<=max;i++)
//    {
//        for(int j=0;j<26;j++){
//            if(j)   cout<<" ";
//            cout<<pos[i][j];
//        }
//        cout<<endl;
//    }
//    return 0;
//}