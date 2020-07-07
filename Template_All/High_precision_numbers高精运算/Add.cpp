#include<bits/stdc++.h>
using namespace std;
int sum[1000],temp[1000];
vector<int> add(vector<int> &a,vector<int> &b){
    if(a.size()<b.size()) return add(b,a); //这里注意将大的放在前面

    vector<int> c;
    int t=0;
    for(int i=0;i<a.size();i++){
        t+=a[i];
        if(i<b.size()) t+=b[i];
        c.push_back(t%10);
        t/=10;
    }
    if(t) c.push_back(t);
    return c;
}
void add(){
    int t=0,i;
    for(i=1;i<=sum[0] || t || i<=temp[0];i++){
        t+=sum[i];
        if(i<=temp[0]) t+=temp[i];
        sum[i]=t%10;
        t/=10;
    }
    sum[0]=max(sum[0],i-1);
}