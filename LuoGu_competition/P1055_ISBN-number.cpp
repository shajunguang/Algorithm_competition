//
// Created by liu on 19-10-8.
//

//#include <bits/stdc++.h>
//using namespace std;
//
//int main()
//{
//    int c,sum=0,code,n=1;
//    string s;
//    getline(cin,s);
//    for(int i=0;i<s.size();i++){
//        c=s[i];
//        if(c>='0' && c<='9')
//            if(n<10)    { sum += (c-'0')*n; n++;}
//    }
//    code=s[s.size()-1];
//    if(sum%11==10){
//        if(code=='X')   printf("Right");
//        else {
//            s.erase(s.size()-1);
//            s +="X";
//            for(int i=0;i<s.size();i++) printf("%c",s[i]);
//        }
//    }
//    else {
//        if (sum % 11 == code - '0')
//            printf("Right");
//        else {
//            s.erase(s.size() - 1);
//            s += to_string(sum % 11);
//            for(int i=0;i<s.size();i++) printf("%c",s[i]);
//        }
//    }
//    return 0;
//}