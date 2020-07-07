#include<bits/stdc++.h>
using namespace std;
const int MAXN=38;
int Fab[MAXN];

void f(){
    Fab[0]=1;Fab[1]=2;
    for(int i=2;i<MAXN;i++) Fab[i]=Fab[i-1]+Fab[i-2];
}

int main()
{
    f();
    int N,num;
    cin>>N;
    while(N--){
        cin>>num;
        int t=num;
        string ans;
        for(int i=MAXN-1;i>=0;i--)
            if(Fab[i]<=num){
                for(int _=0;_<i;_++) ans+='0';
                ans += '1';
                num-=Fab[i];
                break;
            }
        while(num){
            for(int i=MAXN-1;i>=0;i--)
                if(Fab[i]<=num){
                    ans[i]='1';
                    num-=Fab[i];
                    break;
                }
        }
        reverse(ans.begin(),ans.end());
        cout<<t<<" = "<<ans<<" (fib)"<<endl;
    }
    //cout<<Fab[MAXN-1]<<" "<<INT_MAX;
    return 0;
}