#include<bits/stdc++.h>
using namespace std;
const int MAXN=1005;
struct per{
    int order;
    int time;
}person[MAXN];
bool cmp(const per &a,const per &b){
    return a.time<b.time;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>person[i].time,person[i].order=i;
    sort(person+1,person+n+1,cmp);
    long long ans=0;
    for(int i=1;i<=n;i++){
        cout<<person[i].order<<" ";
        ans += person[i].time*(n-i);
    }
    cout<<endl;
    printf("%.2f",(ans+0.0)/n);
    return 0;
}