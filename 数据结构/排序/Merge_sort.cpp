#include<bits/stdc++.h>
using namespace std;
int tmp[100];

void Merge_sort(int q[],int l,int r){
    if(l>=r) return;

    int mid=l+r>>1;

    Merge_sort(q,l,mid);
    Merge_sort(q,mid+1,r);

    int k=0,i=l,j=mid+1;

    while(i<=mid && j<=r){
        if(q[i]<q[j]) tmp[k++]=q[i++];
        else tmp[k++]=q[j++];
    }

    while(i<=mid) tmp[k++]=q[i++];
    while(j<=r) tmp[k++]=q[j++];

    for(i=l,j=0;i<=r;i++,j++) q[i]=tmp[j];
}

int main()
{
    int i,a[10]={5,2,6,0,3,9,1,7,4,8};

    Merge_sort(a, 0, 9);

    printf("After sorted: \n");

    for(i=0;i<10;i++) cout<<a[i]<<" ";

    return 0;
}