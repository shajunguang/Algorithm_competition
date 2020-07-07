#include<bits/stdc++.h>
using namespace std;
const int MAXN=1001; //乘法开两倍,吃大亏一开始
int sum[MAXN]={1,1},temp1[MAXN],temp[MAXN];
void add(int temp[]){
    int t=0,i;
    for(i=1;i<=temp1[0] || t || i<=temp[0];i++){
        if(i>500) break;
        t+=temp1[i];
        if(i<=temp[0]) t+=temp[i];
        temp1[i]=t%10;
        t/=10;
    }
    temp1[0]=max(temp1[0],i-1);
}
void muti(){ //高精乘高精，逐位相乘
    for(int i=1;i<=sum[0];i++) {
        memset(temp,0,sizeof temp);
        int t=0,j;
        for (j = 1; j <= sum[0] || t; j++) {
            //if (j > 500) break;
            if (j <= sum[0]) t += sum[j] * sum[i];
            temp[j+i-1] = t % 10;
            t /= 10;
        }
        temp[0]=max(temp[0],j+i-2); //进位存储
        temp1[0]=max(temp1[0],j-1);
        add(temp);
        //if(temp1[0]>=500) break;
    }
    memcpy(sum,temp1,sizeof sum);
    memset(temp1,0,sizeof temp1);
}
void muti2(){ //sum[0]记录位数
    int t=0,i;
    for(i=1;i<=sum[0] || t;i++){
        if(i<=sum[0]) t+=sum[i]*2;
        sum[i]=t%10;
        t/=10;
    }
    sum[0]=max(sum[0],i-1);
}
//递归多香！
void pow_mod(int P){
  if(P==0) return;
  pow_mod(P>>1);
  muti();
  if(P%2)muti2();
}
//迭代版本
/*
 void pow_mod(int P){
    int temp[MAXN]={1,1};
    while(P>0){
        if(P%2) temp*=sum;//这里需要写高精*高精
        muti();
        P>>=1;
    }
 }
 */
int main()
{
    int P;
    cin>>P;
    pow_mod(P);
    sum[1]-=1;
    cout<<(int)(log10(2)*P)+1<<endl;
    for(int i=500;i>0;i--){
          if(i!=500 && i%50==0)  cout<<endl<<sum[i];
          else cout<<sum[i];
    }
    return 0;
}