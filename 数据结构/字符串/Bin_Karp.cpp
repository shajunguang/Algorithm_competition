//字符串匹配滚动hash
#include<bits/stdc++.h>
using namespace std;
const int MOD=128;

long long Hash(string s){
    long long t=0;
    long long a=1;
    for(auto i:s){
        t+=i*a;
        a*=MOD;
    }
    return t;
}
int Bin_Karp(string s,string t){
    int n=s.size(),m=t.size();
    string s1=s.substr(0,m);
    long long hs=Hash(s1),ht=Hash(t);

    for(int i=0;i<(int)n-m+1;i++){
        if(hs==ht)
            if(s.substr(i,m)==t) return i; //避免hash冲突
        hs=hs/MOD+s[i+m]*pow(MOD,m-1); //计算新一段的[m+1,2*m+1]的hash值
    }
    return -1;
}
int main()
{
    string s="abcdef",t="cd";
    cout<<Bin_Karp(s,t);
    return 0;
}