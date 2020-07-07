#include<bits/stdc++.h>
using namespace std;
const int MAXN=1005;
int nums[MAXN];

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int res=0;
        for(int i=0;i<n;i++){
            cin>>nums[i];
            if(!i) continue;
            int sum=0;
            for(int j=0;j<i;j++)
                if(nums[j]<=nums[i])
                    sum++;
            res+=sum;
        }
        cout<<res<<endl;
    }
    return 0;
}
