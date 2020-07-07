#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6;
struct ma{
    int start;
    int end;
}match[MAXN];
bool cmp(const ma &a,const ma &b){
    if(a.start==b.start) return a.end<b.end;
    return a.start<b.start;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>match[i].start>>match[i].end;
    sort(match,match+n,cmp);
    int ans=1,e=match[0].end;
    for(int i=1;i<n;i++){
        int s1=match[i].start,e1=match[i].end;
        if(s1>=e) ans++,e=e1;
        else if(e1<=e) e=e1;
    }
    cout<<ans;
    return 0;
}