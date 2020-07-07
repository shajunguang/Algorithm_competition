#include<bits/stdc++.h>
using namespace std;
void print(){
    char a;
    cin>>a;
    if(a!='#') print(); //递
    if(a!='#') cout<<a; //归
}


int main()
{
    print();
    return 0;
}