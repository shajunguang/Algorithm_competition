#include<bits/stdc++.h>
using namespace std;

void insertsort(int q[],int l,int r){
    int i,j;

    for(i=l+1;i<=r;i++){
        int key=q[i];
        j=i-1;

        while(j>=l && q[j]>key){
            q[j+1]=q[j];
            j--;
        }

        q[j+1]=key;
    }
}

int main()
{
    int i,a[10]={5,2,6,0,3,9,1,7,4,8};

    insertsort(a, 0, 9);

    printf("After sorted: \n");

    for(i=0;i<10;i++) cout<<a[i]<<" ";

    return 0;
}