//
// Created by liu on 19-10-9.
//

//#include <bits/stdc++.h>
//using namespace std;
//
//bool is_prime(int n){
//    int m=sqrt(n+0.5);
//    for(int i=2;i<=m;i++)
//        if(n%i==0)  return false;
//    return true;
//}
//
//int main()
//{
//    int a,b;
//    cin>>a>>b;
//    string s;
//    vector<int> prime;
//    for(int i=a;i<=b;){
//        s=to_string(i);
//        int flag=1;
//        for(int j=0;j<s.size()/2;j++){
//            if(s[j]!=s[s.size()-j-1]){
//                flag=0;
//                break;
//            }
//        }
//        if(flag){
//            if(is_prime(i)) prime.push_back(i);
//        }
//        if(a%2==0)  i++;
//        else    i+=2;
//    }
//    int j=0;
//    for(auto i:prime){
//        if(j)   cout<<",";
//        cout<<i;
//        j++;
//    }
//    cout<<endl;
//    cout<<prime.size();
//    return 0;
//}