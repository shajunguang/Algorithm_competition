//82*6 t=12 c={2} t=1->t=49 c={2,9} t=4->c={2,9,4} t=0->end
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6;
int sum[MAXN]={1,1},sav[MAXN];
vector<int> mul(vector<int> &a,int b){
    vector<int> c;
    int t=0;
    for(int i=0;i<a.size() || t;i++){ //这里这个||t太精髓了吧，之后的位也保留进来
        if(i<a.size()) t+=a[i]*b;
        c.push_back(t%10); //除余保留
        t/=10; //进位
    }
    return c;
}
//高精乘高精
vector<int> mul_2(vector<int>&a,vector<int>&b){
    vector<int> c(a.size()+b.size(),0);
    for(int i=0;i<a.size();i++)for(int j=0;j<b.size();j++) c[i+j]+=a[i]*b[j];
    for(int i=0;i<c.size()-1;i++){
        c[i+1]+=c[i]/10;
        c[i]%=10;
    }
    while(c,size()>0 && c.back()==0) c.pop_back();
}
//另一种写法（高精乘高精）
void muti_2(int temp[]){
    for(int i=1;i<=sum[0];i++)for(int j=1;j<=temp[0];j++) sav[i+j-1]+=sum[i]*temp[j];
    int count=sum[0]+temp[0];
    for(int i=1;i<count;i++) sav[i+1]+=sav[i]/10,sav[i]%=10;
    //统计位数
    while(count>0 && sav[count]==0) count--;
    sav[0]=max(sav[0],count);
    memcpy(sum,sav,sizeof sav);
}

void muti(int x){ //sum[0]记录位数
    int t=0,i;
    for(i=1;i<=sum[0] || t;i++){
        if(i<=sum[0]) t+=sum[i]*x;
        sum[i]=t%10;
        t/=10;
    }
    sum[0]=max(sum[0],i-1);
}
int main()
{
    for(int i=10;i<13;i++) muti(i);
    for(int i=sum[0];i>0;i--) cout<<sum[i];
    return 0;
}
