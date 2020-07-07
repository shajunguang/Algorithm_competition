#include<bits/stdc++.h>
using namespace std;

void swap(char* a,char *b,int size){
    char temp;
    do{
        temp=*a;
        *a++=*b;
        *b++=temp;
    }while(--size);
}

int main()
{
    char a[4]="abc";
    char b[4]="bcd";
    swap(a,b,4);
    printf("%s %s",a,b);
}