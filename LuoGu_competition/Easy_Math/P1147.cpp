#include<bits/stdc++.h>
using namespace std;
int main()
{
    int M;cin>>M;
    int sum=3;
    for(int i=1,j=2;i<=M/2;){
        if(sum==M) cout<<i<<" "<<j<<endl,sum-=i,i++;
        else if(sum>M) sum-=i,i++;
        else j++,sum+=j;
    }
    return 0;
}