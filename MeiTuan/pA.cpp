#include<bits/stdc++.h>
using namespace std;
const int MAXN=20005;
int nums[MAXN];

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>nums[i];
    sort(nums,nums+n);
    long long sum=0;
    if(n<3) for(int i=0;i<n;i++) sum+=nums[i];
    else sum+=nums[n-1]+nums[n-2]+nums[n-3];
    for(int i=0;i<n;i++) cin>>nums[i];
    sort(nums,nums+n);
    long long sum1=0;
    if(n<3) for(int i=0;i<n;i++) sum1+=nums[i];
    else sum1+=nums[n-1]+nums[n-2]+nums[n-3];
    cout<<(sum>sum1?sum:sum1)<<endl;
    return 0;
}