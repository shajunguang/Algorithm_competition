#include<bits/stdc++.h>
using namespace std;

int partition(int q[],int l,int r){
    int i=l,j=r;
    int key=q[l];
    while(i<j){
       while(i<j && q[j]>=key) j--;
       q[i]=q[j];
       while(i<j && q[i]<=key) i++;
       q[j]=q[i];
    }
    q[i]=key;
    return j;
}

void Quick_sort(int q[],int l,int r){
    if(l>=r) return;

    int p=partition(q,l,r);
    Quick_sort(q,l,p-1);
    Quick_sort(q,p+1,r);
}

int main()
{
    int i,a[10]={5,2,6,0,3,9,1,7,4,8};

    Quick_sort(a, 0, 9);

    printf("After sorted: \n");

    for(i=0;i<10;i++) cout<<a[i]<<" ";

    return 0;
}