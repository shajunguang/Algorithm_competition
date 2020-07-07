//1初始序列,1->01,0->10,第二次就是01,第三次就是1001,问n次转换,00的个数
//令A为10,B为01,通过递推树可得到下面递推式
//FA[i]=FB[i-1]+FA[i-1],FB[i]=FA[i-1]+FB[i-1]+imod2;与旁边隔代产生00

#include<bits/stdc++.h>
using namespace std;

int FA[1001],FB[1001];
int sum[100],temp[100];

void add(){
    int t=0,i;
    for(i=1;i<=sum[0] || t || i<=temp[0];i++){
        t+=sum[i];
        if(i<=temp[0]) t+=temp[i];
        sum[i]=t%10;
        t/=10;
    }
    sum[0]=max(sum[0],i-1);
}

int main()
{
    int n;
    FA[1]=0,FB[1]=1;
    for(int i=2;i<1001;i++){
        FA[i]=FB[i-1]+FA[i-1];
        FB[i]=FA[i-1]+FB[i-1]+i%2;
    }
    while(cin>>n){
        cout<<FB[n-1]<<endl;
    }

    return 0;
}