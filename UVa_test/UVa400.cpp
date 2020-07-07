//
// Created by liu on 19-8-19.
//
//
//#include <iostream>
//#include <string>
//#include <algorithm>
//#define local
//using namespace std;
//
//const int maxcol = 60;
//const int maxn = 100 +5;
//string filenames[maxn];
//
////输出字符串s，长度不足len时补字符extra
//void print(const string& s, int len, char extra){
//    cout<<s;
//    for(int i=0;i<len-s.length();i++)
//        cout<<extra;
//}
//
//int main()
//{
//#ifdef local
//    freopen("in.txt","r",stdin);
//    //freopen("out.txt","w",stdout);
//#endif
//    int n;
//    while(cin>>n){
//        int M=0;
//        for(int i=0;i<n;i++){
//            cin>>filenames[i];
//            M = max(M, (int)filenames[i].length());  //STL的max
//        }
//        //计算列数cols和行数rows
//        int cols = (maxcol-M) / (M+2) +1,rows = (n-1)/cols +1;
//        print("",60,'-');
//        cout<<endl;
//        sort(filenames,filenames+n);
//        for(int r=0;r<rows;r++){
//            for(int c=0;c<cols;c++){
//                int idx = c*rows+r;  // 输出位置的表示
//                if(idx<n)   print(filenames[idx], c==cols-1?M:M+2,' ');
//            }
//            cout<<endl;
//        }
//    }
//    return 0;
//}