//纯逻辑问题，判断输入的数奇偶，以及当前哪个玩家先走，偶数先走赢，奇数后走赢
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,player=1;
    cin>>n;
    for(int i=0,a;i<n;i++){
        cin>>a;
        if(player==1){
            if(a%2) {cout<<2<<endl;player=1;}
            else{cout<<1<<endl;player=2;}
        }else{
            if(a%2){cout<<1<<endl;player=2;}
            else{cout<<2<<endl;player=1;}
        }
    }
    return 0;
}