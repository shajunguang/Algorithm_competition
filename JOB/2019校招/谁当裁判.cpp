#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int num[MAXN];
int main()
{
    //freopen("in/txt","r",stdin);
    int N;
    cin>>N;
    for(int i=0;i<N;i++) cin>>num[i];
    sort(num,num+N);
    int ans=0;
    while(num[N-1]){
        for(int i=1;i<N;i++)
            if(num[i]){
                num[i]--;
                if(num[i]<num[i-1]) swap(num[i],num[i-1]);
            }
        ans++;
    }
    cout<<ans<<endl;
}