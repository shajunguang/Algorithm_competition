#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
bool cmp(PII &a, PII &b){
    if(a.first==b.first) return a.second>b.second;
    return a.first<b.first;
}
int main()
{
    freopen("in.txt","r",stdin);
    vector<PII> job;
    int n,m;
    cin>>n>>m;
    int a,b;
    for(int i=1;i<=n;i++){
        cin>>a>>b;
        job.emplace_back(make_pair(a,b));
    }
    sort(job.begin(),job.end(),cmp);
    int max=job[0].second;
    for(int i=1;i<n;i++){
        if(job[i].second>max) max=job[i].second;
        else job[i].second=max;
    }
    int c;
    for(int i=0;i<m;i++){
        cin>>c;
        int l=0,r=n-1;
        while(l<r){
            int mid=l+r+1>>1;
            if(job[mid].first<=c)  l=mid;
            else r=mid-1;
        }
        cout<<job[l].second<<endl;
    }
    return 0;
}