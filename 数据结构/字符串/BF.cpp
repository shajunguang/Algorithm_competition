//字符串匹配，BF brute force暴力求解
#include<bits/stdc++.h>
using namespace std;
//判断str1是否str2子串
bool is_comparable(string str1,string str2){
    if(str1.empty())return true;
    if(str1.size()>str2.size()) return false;
    for(int i=0;i<(int)str2.size();i++)
            if(str1[0]==str2[i]){
                int j=0,f=1;
                while(j<str1.size()) {
                    if(str1[j]==str2[i+j]) j++;
                    else {f=0;break;}
                }
                if(f) return true;
            }
    return false;
}
int main()
{
    string s1="sad",s2="sadqweuasd";
    if(is_comparable(s1,s2)) cout<<1<<endl;
    else cout<<0<<endl;
    return 0;
}