//寻找最大间隔最小，一维数据，其实就是最大最小值的中间值，间隔得遍历下
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
int f[MAXN],g[MAXN];
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
//        memset(f,0,sizeof f);
//        memset(g,0,sizeof g);
        for(int i=1;i<=n;i++) cin>>f[i];
        int cnt=0;
        for(int i=1;i<=n;i++)
            if(f[i]==-1){
                if(i+1<=n&&f[i+1]!=-1) g[++cnt]=f[i+1];
                if(i-1>=1&&f[i-1]!=-1) g[++cnt]=f[i-1];
            }
        sort(g+1,g+cnt+1);
        int mid=(g[1]+g[cnt])/2;
        for(int i=1;i<=n;i++) if(f[i]==-1) f[i]=mid;
        int ans=0;
        for(int i=1;i<n;i++) ans=max(ans,abs(f[i+1]-f[i]));
        cout<<ans<<" "<<mid<<endl;
    }
    return 0;
}