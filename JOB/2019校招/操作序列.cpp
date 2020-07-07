//map是有序的，且删除操作和vector一样，而且查询不用迭代的方式，用find方式查询下标是否存在！！！

#include<bits/stdc++.h>
using namespace std;

int main()
{
    map<int,int> hash;
    int n;
    cin>>n;
    while(n--){
        int t,c=-1;
        cin>>t;
        char d=getchar();
        if(d==' ') cin>>c;
        if(c!=-1){
            int flag=1;
            for(int i=t-30;i<=t+30;i++) if(hash.find(i)!=hash.end()) {flag=0;break;}
            if(flag)hash[t]=c;
        }
        else{
            if(t==-1){
                if(hash.empty())cout<<"skipped"<<endl;
                else{
                    cout<<hash.begin()->second<<endl;
                    hash.erase(hash.begin());
                }
            }
            else{
                if(hash.find(t)!=hash.end()) cout<<hash[t]<<endl;
                else cout<<0<<endl;
            }
        }
    }
    return 0;
}