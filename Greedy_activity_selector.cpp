//
// Created by liu on 19-9-9.
//

//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//int s[50],f[50];
//vector<int> A;
//
//void greedy_activity_selector(int n){
//    A.push_back(1);
//    int k=0;
//    for(int m=1;m<n;m++){
//        if(s[m]>=f[k]){
//            A.push_back(m+1);
//            k=m;
//        }
//    }
//}
//
//int main()
//{
//    for (int i = 0; i < 11; i++)
//        cin >> s[i];
//    for (int i = 0; i < 11; i++)
//        cin >> f[i];
//    greedy_activity_selector(11);
//    for(int i=0;i<A.size();i++)
//        cout<<"a"<<A[i]<<" ";
//    cout<<endl;
//}