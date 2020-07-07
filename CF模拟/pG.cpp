#include<bits/stdc++.h>
using namespace std;
int main()
{
    set<pair<int,int> > s;
    map<pair<int,int>,int> h;
    int n,x0,y0;
    cin>>n>>x0>>y0;
    for(int i=0,x,y;i<n;i++){
        cin>>x>>y;
        pair<int,int> p;
        int g=__gcd(x-x0,y-y0);
        if(y-y0==0)
            p=make_pair(1,0);
        else if(x-x0==0) p=make_pair(0,1);
        else p=make_pair((x-x0)/g,(y-y0)/g);
        if(!h[p]){
                h[p]=1;
                s.insert(p);
            }
    }
    cout<<s.size()<<endl;
    return 0;
}