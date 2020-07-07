#include<bits/stdc++.h>
using namespace std;
/*
 int& int::operator++ ()
{
     *this +=1;
     return *this;
}
const int int ::operator(int)
{
     int oldValue = *this;
     ++(*this);
     return oldValue;
}
 */
int main()
{
    int i=2;
    string name;
    for(int j=0;j<3;j++) {
        i=i++;
        cout<<i<<endl;
    }
    return 0;
}
