#include<bits/stdc++.h>
using namespace std;

class{
private:
    bool a;  // |a - - -|
    int b;   // |    b  |
    bool c;  // |c - - -|
}A;
class{
private:
    bool b;  //|b c - -|
    bool c;
    int a;   //|   a   |
}B;

int main()
{
    cout<<sizeof(A)<<endl; //sizeof计算栈中的
    cout<<sizeof(B)<<endl;
}