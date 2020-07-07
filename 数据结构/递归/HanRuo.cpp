#include<bits/stdc++.h>
using namespace std;

//将a上的n个从大到小的盘借助b移到c
void move(int n,char a,char b,char c){
    if(n==1){
        cout<<a<<"->"<<c<<endl;
        return;
    }
    move(n-1,a,c,b); //现将n-1个盘从a借助c移到b
    move(1,a,b,c);  //将第n个盘从a移到c
    move(n-1,b,a,c);//将n-1个盘从b借助a移到c
}

int main()
{
    move(4,'x','y','z');
    return 0;
}