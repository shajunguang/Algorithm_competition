#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int nums[MAXN];

int main()
{
    int n,max=0,pos=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>nums[i];
        if(nums[i]>max) max=nums[i],pos=i;
    }
    int m1=max,m2=max,f1=1,f2=1;
    for(int i=pos-1;i>=0;i--){
        if(nums[i]<m1) m1=nums[i];
        else {f1=0;break;}
    }
    for(int i=pos+1;i<n;i++){
        if(nums[i]<m2) m2=nums[i];
        else {f2=0;break;}
    }
    if(f1 && f2) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}