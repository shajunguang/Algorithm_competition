////
//// Created by liu on 19-10-17.
////
//
//#include <bits/stdc++.h>
//#define local
//using namespace std;
//
//map<char,int> arr;
//
//int stringtoint(string &s){
//    int t=0;
//    for(char i : s)
//        t= t*10+i-'0';
//    return t;
//}
//
//bool is_arr(string &s){
//    if((s[0]>='a' && s[0]<='z') || (s[0]>='A' && s[0]<='Z'))
//        if(s[1]=='[' &&  s[s.size()-1]==']')
//        {
//            string temp=s.substr(2,s.size()-3);
//            if(stringtoint(temp)<=INT_MAX)
//                return true;
//        }
//    return false;
//}
//
//int main()
//{
//    string temp,before;
//    int res,i=1;
//    while(getline(cin,temp))
//    {
//        if(temp==before && temp==".")   break;
//        before=temp;
//        if(temp==".") continue;
//        //心态崩了,写不下了,看题解去了,这题跳过
//    }
//}