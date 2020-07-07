#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
vector<PII> nums;
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int p,a;
        cin>>p>>a; nums.emplace_back(make_pair(p,a));
    }
    sort(nums.begin(),nums.end());
    long long ans=0;
    for(auto num:nums){
        if(!n) break;
        if(num.second<=n) ans+=num.first*num.second,n-=num.second;
        else ans+=num.first*n,n=0;
    }
    cout<<ans;
    return 0;
}