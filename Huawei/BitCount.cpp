#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,ans=0;
    cin>>n;
    while(n){
        n=n&n-1;
        ans++;
    }
    cout<<ans;
    return 0;
}