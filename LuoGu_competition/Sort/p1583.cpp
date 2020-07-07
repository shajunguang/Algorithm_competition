//真他妈菜啊，这种需要绑定多个属性的，用结构体啊！！！
#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e4+5;
struct per{
    int init;
    int w;
}p[MAXN];
bool operator < (per const &a, per const &b){
    if(a.w!=b.w) return a.w>b.w;
    return a.init<b.init;
}
int main()
{
    freopen("in.txt","r",stdin);
    int n,k,E[11];
    cin>>n>>k;
    for(int i=1;i<11;i++) cin>>E[i];
    for(int i=1;i<=n;i++) cin>>p[i].w,p[i].init=i;
    sort(p+1,p+n+1);
    for(int i=1;i<=n;i++) p[i].w += E[(i-1)%10+1];
    sort(p+1,p+n+1);
    for(int i=1;i<=k;i++) cout<<p[i].init<<" ";
    return 0;
}