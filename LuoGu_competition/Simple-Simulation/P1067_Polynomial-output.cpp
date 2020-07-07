//
// Created by liu on 19-10-12.
//

//#include <bits/stdc++.h>
//using namespace std;
//
//int main()
//{
//    int n,k;
//    string res;
//    cin>>n;
//    if(!n)  cout<<"1";
//    else{
//        for(int i=n;i>=0;i--){
//            cin>>k;
//            if(!k) continue;
//            if(k>0){
//                if(i==n)    res+=k==1?"x^"+to_string(i):to_string(k)+"x^"+to_string(i);
//                else if(i>1)    res +=k==1?"+x^"+to_string(i):"+"+to_string(k)+"x^"+to_string(i);
//                else if(i==1)   res +=k==1?"+x":"+"+to_string(k)+"x";
//                else    res+="+"+to_string(k);
//            }
//            else{
//                if(i>1)    res +=k==-1?"-x^"+to_string(i):to_string(k)+"x^"+to_string(i);
//                else if(i==1)   res +=k==-1?"-x":to_string(k)+"x";
//                else    res+=to_string(k);
//            }
//        }
//    }
//    cout<<res;
//    return 0;
//}