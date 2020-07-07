//
// Created by liu on 19-10-8.
//

//#include <bits/stdc++.h>
//using namespace std;
//
//int main()
//{
//    string s,res;
//    cin>>s;
////    int pos1=s.find('.');
////    int pos2=s.find('/');
////    int pos3=s.find('%');
//    int flag=0;
//    for(int i=0;i<s.size();i++){
//        unsigned long long n=1,sum=0;
//        while(i<s.size() && s[i] !='.' && s[i]!='/' && s[i]!='%'){
//            sum += (s[i]-'0')*n;
//            n *= 10;
//            i++;
//        }
//        if(s[i]=='.')   flag=1;
//        if(i<s.size())  res += to_string(sum)+s[i];
//        else    res += to_string(sum);
//    }
//    if(flag){
//        for(int i=res.size()-1;i>=0;i--){
//            if(res[i]=='0'){
//                if(res[i-1]!='.')
//                    res.erase(res.begin()+i);
//                else break;
//            } else  break;
//        }
//    }
//    cout<<res;
//    return 0;
//}

//#include <bits/stdc++.h>
//using namespace std;
//
//int main()
//{
//    string s,res;
//    cin>>s;
////    int pos1=s.find('.');
////    int pos2=s.find('/');
////    int pos3=s.find('%');
//    int flag=0;
//    for(int i=0;i<s.size();i++){
//        string temp;
//        while(i<s.size() && s[i] !='.' && s[i]!='/' && s[i]!='%'){
//            temp += s[i];
//            i++;
//        }
//        if(s[i]=='.')   flag=1;
//        reverse(temp.begin(),temp.end());
//        if(i<s.size())  res += temp + s[i];
//        else    res += temp;
//    }
//    int i=0;
//    while(i<res.size() && res[i]=='0'){
//        if(res[i+1]!='/' && res[i+1]!='.' && res[i+1]!='%')
//            res.erase(res.begin()+i);
//        else    break;
//    }
//    if(flag){
//        for(int i=res.size()-1;i>=0;i--){
//            if(res[i]=='0'){
//                if(res[i-1]!='.')
//                    res.erase(res.begin()+i);
//                else break;
//            } else  break;
//        }
//    }else{
//        int pos = res.find('/');
//        while(pos != -1 && pos<res.size()-2 && res[pos+1]=='0'){
//            res.erase(res.begin()+pos+1);
//        }
//    }
//    cout<<res;
//    return 0;
//}