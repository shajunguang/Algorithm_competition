#include<bits/stdc++.h>
using namespace std;

void down(vector<int>&a,int i,int n){
    int u=i;
    if(2*i+1<n && a[2*i+1]>a[u]) u=2*i+1;
    if(2*i+2<n && a[2*i+2]>a[u]) u=2*i+2;
    if(u!=i){
        swap(a[u],a[i]);
        down(a,u,n);
    }
}
void heap_sort(vector<int>&a,int n){
    //建堆
    for(int i=n/2-1;i>=0;i--) down(a,i,n);
    for(int i=n-1;i>0;i--){
        swap(a[i],a[0]);
        down(a,0,i);
    }
}
int main()
{
    vector<int> a={4,3,5,2,1};
    heap_sort(a,5);
    for(auto i:a)cout<<i<<" ";
    return 0;
}