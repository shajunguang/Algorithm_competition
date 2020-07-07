#include<bits/stdc++.h>
using namespace std;
typedef pair<double,double> PII;
int n,vis[16];
double sum=0.0,ans=200000000.0;
vector<PII> pos;
//dfs(int step,int now,int length) 其中step表示移动步数，now当前点，length表示长度
void dfs(double x,double y,int cur){
    if(cur==n){
        if(sum<ans) ans=sum;
        return ;
    }
    double temp;
    for(int i=0;i<n;i++)
        if(!vis[i]){
            vis[i]=1;
            temp=sqrt((pos[i].first-x)*(pos[i].first-x)+(pos[i].second-y)*(pos[i].second-y));
            sum+=temp;
            if(sum>ans){ //某条分支超了，减掉
                vis[i]=0;
                sum-=temp;
                return;
            }
            dfs(pos[i].first,pos[i].second,cur+1);//这里千万别用++cur，同层就会改变层数，回溯出错
            vis[i]=0;
            sum-=temp;
        }
}


int main()
{
    cin>>n;
    for(int i=0;i<n;i++){
        double a,b;
        cin>>a>>b;
        pos.emplace_back(make_pair(a,b));
    }
    memset(vis,0,sizeof vis);
    dfs(0,0,0);
    printf("%.2f\n",ans);
    return 0;
}