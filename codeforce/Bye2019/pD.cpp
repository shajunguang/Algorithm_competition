//x1,x2...xm,xm+1,...xk+1 排序好的数列，
// 显然xm+1要出现，就得前m个数消失一个，也就是说xm+1会消失m次，统计次数即可！！！
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    map<int,int> cnt;
    for(int i=1;i<=k+1;i++){
        cout<<"? ";
        for(int j=1;j<=k+1;j++) if(i!=j) cout<<j<<" "; //每次访问k个元素，访问k+1次
        cout<<endl;cout.flush();
        int x,y;cin>>x>>y;cnt[y]++;
    }
    cout<<"! "<<(*cnt.rbegin()).second<<endl;
    return 0;
}
