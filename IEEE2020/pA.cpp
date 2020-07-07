#include<bits/stdc++.h>
using namespace std;
int Joseph(int m,int k,int i)
{
    if(m==1) return 0;
    return ((Joseph(m-1,k,i+1)+(int)pow(k,i))%m);
}

int main()
{
    int m,k;
    cin>>m>>k;
    cout<<Joseph(m,k,1)+1<<endl;

    return 0;
}
