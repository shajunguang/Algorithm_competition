#include<bits/stdc++.h>
using namespace std;
const int MAXN=1005;
int sum[20010],add[20010],ans[20010];//sum记录最后余数数组，add每个大臣余数，ans记录乘积
struct per{
    int left;
    int right;
}person[MAXN];
bool cmp(const per &a,const per &b){
    //if(a.right*a.left==b.right*b.left) return a.right<b.right;
    return a.right*a.left<b.right*b.left;
}
//int*高精度
void times(int x){
    memset(add,0,sizeof add);
    for(int i=1;i<=ans[0];i++){ //模拟乘法计算,ans[0]记录位数
        ans[i]*=x;
        add[i+1]+=ans[i]/10;
        ans[i]%=10;
    }
    for(int i=1;i<=ans[0]+4;i++){ //每次乘最大1e4,因此往后移4位，统计最新位数
        ans[i]+=add[i];//加上低位进上的数，超过10再给后面加
        if(ans[i]>=10){ans[i+1]+=ans[i]/10;ans[i]%=10;}
        if(ans[i]!=0) ans[0]=max(ans[0],i); //记录位数
    }
}
void divition(int x){
    memset(add,0,sizeof add);
    int q=0;
    for(int i=ans[0];i>=1;i--){
        q*=10;q+=ans[i];
        add[i]=q/x;
        if(add[0]==0 && add[i]!=0) add[0]=i;
        q%=x;
    }
}
bool compare(){ //记录更大的余数
    if(sum[0]==add[0]) //如果位数一样，就依次比较
        for(int i=add[0];i>=1;i--){
            if(add[i]>sum[i]) return true;
            if(add[i]<sum[i]) return false;
        }
    if(add[0]>sum[0]) return true;
    if(add[0]<sum[0]) return false;
}
void cp(){ //复制到答案sum数组中(更新）
    memset(sum,0,sizeof sum);
    for(int i=add[0];i>=0;i--) sum[i]=add[i];
}
int main()
{
    freopen("in.txt","r",stdin);
    int n,a,b;
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++) cin>>person[i].left>>person[i].right;
    sort(person+1,person+n+1,cmp);
    ans[0]=ans[1]=1;
    for(int i=1;i<n;i++) {
        times(person[i].left);
        divition(person[i+1].right);
        if(compare()) cp();
    }
    //if(sum[0]==0) cout<<"0";
    for(int i=sum[0];i>=1;i--)cout<<sum[i];
    return 0;
}