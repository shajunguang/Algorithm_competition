//问题等价于i对×n-i对不交叉情况求和,公式sum(Ci*Cn-i),卡特兰数,偷懒就打表了
#include<bits/stdc++.h>
using namespace std;
int C[10]={1,2,5,14,42,132,429,1430,4862,16796};
int main()
{
    int n,Case=0;
    while(cin>>n){
        if(Case++) cout<<endl;
        cout<<C[n-1]<<endl;
    }
    return 0;
}