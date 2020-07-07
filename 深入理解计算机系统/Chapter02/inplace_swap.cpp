//实现x,y交换
#include<stdio.h>

void inplace_swap(int *x,int *y){
    *y=*x ^ *y;
    *x=*x ^ *y;
    *y=*x ^ *y;

}

void reverse_array(int a[],int cnt){
    int first,last;

    for(first=0,last=cnt-1;first<last;first++,last--) inplace_swap(&a[first],&a[last]);
}

int main()
{
    int x=1,y=2;
    inplace_swap(&x,&y);
    printf("%d %d\n",x,y);
    int a[5]={1,2,3,4,5};
    reverse_array(a,5);
    for(auto i:a) printf("%d ",i);

    return 0;
}