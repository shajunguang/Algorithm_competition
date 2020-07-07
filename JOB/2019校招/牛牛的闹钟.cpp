#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
bool cmp(PII &a,PII &b){
    if(a.first==b.first)return a.second<b.second;
    return a.first<b.first;
}
int main()
{
    freopen("in.txt","r",stdin);
    vector<PII> clock;
    int n;
    cin>>n;
    for(int i=0,a,b;i<n;i++){
        cin>>a>>b;
        clock.emplace_back(make_pair(a,b));
    }
    sort(clock.begin(),clock.end(),cmp);
    int x;cin>>x;
    int A,B;cin>>A>>B;
    if(B<x) A-=1+((x-B)/60),B=(B-x+60)%60;
    else B-=x;
    //auto p=upper_bound(clock.begin(),clock.end(),make_pair(A,B));
    //p--;
    int i=0;
    for(;i<n;i++){
        if(clock[i].first>A) break;
        if(clock[i].first==A && clock[i].second>B) break;
    }
    i--;
    cout<<clock[i].first<<" "<<clock[i].second<<endl;
    return 0;
}