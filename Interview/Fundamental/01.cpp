#include<bits/stdc++.h>
using namespace std;
int i=1;
int main()
{
    int i=i; //未定义的值
    //cout<<i<<endl;
    int x=2,y,z;
    x*=(y=z=5); cout<<x<<endl;
    z=3;
    x==(y=z); cout<<x<<endl;
    x=(y==z); cout<<x<<endl;
    x=(y&z); cout<<x<<endl;
    x=(y&&z); cout<<x<<endl;
    y=4;
    x=(y|z); cout<<x<<endl;
    x=(y||z); cout<<x<<endl;
    return 0;
}