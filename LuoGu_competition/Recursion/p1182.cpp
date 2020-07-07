//本题求最大值的最小值，因此采用二分答案思想，答案是区间内最小值到区间和
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int n,m,a[MAXN],l=0,r=0;
bool check(int x){
    int tot=0,count=0;
    for(int i=0;i<n;i++){
        if(tot+a[i]<=x) tot+=a[i];
        else tot=a[i],count++;
    }
    return count>=m;
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        l=max(a[i],l);
        r+=a[i];
    }
    while(l<r){
        int mid=l+r>>1;
        if(check(mid)) l=mid+1;
        else r=mid;
    }
    cout<<l<<endl;
    return 0;
}