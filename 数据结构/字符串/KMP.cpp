#include<bits/stdc++.h>
using namespace std;
int ne[100];
//BF,s匹配t从pos位置开始
int BF(string s,string t,int pos){
    int i=pos,j=0;
    while(i<s.size() && j<t.size()){
        if(s[i]==t[j]){
            i++;
            j++;
        }else{
            i=i-j+1;
            j=0;
        }
    }
   if(j>=t.size())return i-t.size();
   else return -1;
}
//获取next数组
void get_next(string t){
    int i=1,j=0;
    ne[1]=0;
    while(i<t.size()){
        if(j==0 || t[i-1]==t[j-1]){ //j==0避免一开始不一样，死循环了
            i++;
            j++;
            if(t[i-1]==t[j-1])//特殊情况，i失配，但j却和i一样，并不能匹配，因此要移到ne[j]才对
                ne[i]=ne[j];
            else ne[i]=j;
        } else j=ne[j];//回溯到ne[j]的位置
    }
}
int KMP(string s,string t,int pos){
    int i=pos,j=1;
    get_next(t);
    while(i<s.size() && j<=t.size()){
        if(j==0 || s[i]==t[j-1]){
            i++;
            j++;
        }else j=ne[j]; //回溯
    }
    if(j>t.size()) return i-t.size();
    else return -1;
}
int main()
{
    string s="qwedf",t="abcabcd";
    cout<<BF(t,s,0)<<endl;
    cout<<KMP(s,t,0)<<endl;
    return 0;
}