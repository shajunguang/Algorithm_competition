#include<bits/stdc++.h>
using namespace std;
const int MAXN=105;
int nums[MAXN];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++) cin>>nums[i];
    sort(nums,nums+n);
    for(int i=0;i<n;i++) cout<<nums[i]<<" ";
    return 0;
}