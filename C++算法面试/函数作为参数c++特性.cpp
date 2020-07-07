#include<bits/stdc++.h>
using namespace std;

int f(int x){
    return x;
}


int g(int x, function<int(int)> f) {
    return 3+f(x);
}

int main()
{
    cout<<g(5,f)<<endl;
    return 0;
}