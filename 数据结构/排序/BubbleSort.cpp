#include<bits/stdc++.h>

using namespace std;

void BubbleSort(int q[],int l,int r){

   int i,j,flag=1,count=0; //flag表示是否进行过交换,没有进入比较,表示排序完成结束

   for(i=l;flag;i++){
       flag=0;
       for(j=r;j>i;j--){
           if(q[j]<q[j-1]){
               count++;
               swap(q[j],q[j-1]);
               flag=1;
           }
       }
   }
   printf("进行了多少次比较: %d,进行多少次移动: %d.\n",i,count);
}

int main(){
    int i,a[10]={5,2,6,0,3,9,1,7,4,8};

    BubbleSort(a, 0, 9);

    printf("After sorted: \n");

    for(i=0;i<10;i++) cout<<a[i]<<" ";

    return 0;
}