//最大连续子串和
#include<bits/stdc++.h>
using namespace std;
int lis(int q[],int n){
    int ans=0,Max=0;
    for(int i=0;i<n;i++){
        ans+=q[i];
        Max=max(Max,ans);
        if(ans<0){
            ans=0;
        }
    }
    return Max;
}

int main()
{
    int q[5]={1,-1,2,-1,4};
    cout<<lis(q,5)<<endl;
    return 0;
}