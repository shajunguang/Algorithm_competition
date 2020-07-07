#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5;
int nums[MAXN];

int main()
{
    int N,M;
    cin>>N>>M;
    for(int i=0;i<N;i++) cin>>nums[i];
    int ans=0;
    for(int i=0;i<N;){
        int sum=nums[i];
        while(i<N && sum<=M) sum+=nums[++i];
        ans++;
    }
    cout<<ans;
    return 0;
}