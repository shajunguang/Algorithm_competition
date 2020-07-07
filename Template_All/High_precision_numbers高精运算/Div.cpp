//98/5  r=9 c={1} r=4 -> r=48 c={1,9} r=3 -> end c={9,1}
//37/5  r=3 c={0} r=3 -> r=37 c={0,7} r=2 -> end c={7,0} -> c={7} r=2;
#include<bits/stdc++.h>
using namespace std;
vector<int> div(vector<int> &a,int b,int &r){ //注意这里r是引用参数，可修改的
    vector<int> c;
    r=0; //余数
    for(int i=a.size()-1;i>=0;i--){
        r=r*10+a[i];
        c.push_back(r/b);
        r%=b;
    }
    reverse(c.begin(),c.end());
    while(c.size()>1 && c.back()==0)c.pop_back();//去掉前置0
    return c;
}