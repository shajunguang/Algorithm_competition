#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    while(cin>>n){
        int count=0;
        for(int i=2;i*i<=n;i++){
            while(n%i==0){ //这里一定保证是质因子,无需判断
                n/=i;
                count++;
            }
        }
        if(n!=1) count++;
        cout<<count<<endl;
    }
}