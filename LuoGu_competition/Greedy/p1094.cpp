#include<bits/stdc++.h>
using namespace std;
const int MAXN=3e4;
int nums[MAXN];

int main()
{
    int w,n;
    cin>>w>>n;
    for(int i=0;i<n;i++) cin>>nums[i];
    sort(nums,nums+n);
    int i=0,j=n-1,ans=0;
    while(i<j) {
        if (nums[i] + nums[j] <= w) i++, j--, ans++;
        else j--, ans++;
        if (i == j) ans++;
    }
    cout<<ans;
    return 0;
}