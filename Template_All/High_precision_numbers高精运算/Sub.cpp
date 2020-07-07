#include<bits/stdc++.h>
using namespace std;
vector<int> sub(vector<int> &a,vector<int> &b){
    vector<int> c;
    for(int i=0,t=0;i<a.size();i++){
        t=a[i]-t;
        if(i<b.size()) t-=b[i];
        c.push_back((t+10)%10);
        if(t<0) t=1; //不足往前借位
        else t=0;
    }
    while(c.size()>1 && c.back()==0) c.pop_back(); //去掉前置0
    return c;
}