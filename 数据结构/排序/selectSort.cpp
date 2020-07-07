#include<bits/stdc++.h>
using namespace std;

void SelectSort(int q[],int l,int r){
    int i,j,minv;

    for(i=l;i<=r;i++) {
        minv=i;
        for (j = i + 1; j <= r; j++) {
            if(q[j]<q[minv]) minv=j;
        }
        swap(q[i],q[minv]);
    }
}

int main(){
    int i,a[10]={5,2,6,0,3,9,1,7,4,8};

    SelectSort(a, 0, 9);

    printf("After sorted: \n");

    for(i=0;i<10;i++) cout<<a[i]<<" ";

    return 0;
}