#include<bits/stdc++.h>
using namespace std;
int vis[10],n;
void Combination(char* s,int pos,int k){
    if(k==0){
        for(int i=0;i<n;i++) if(vis[i]) cout<<s[i];
        cout<<endl;
        return;
    }
    for(int i=pos;i<n;i++)
        if(!vis[i]){
            vis[i]=1;
            Combination(s,i+1,k-1);
            vis[i]=0;
        }
}

int main()
{
    char s[5]="abcd";
    n=4;
    for(int i=1;i<=n;i++) {
        memset(vis,0,sizeof vis);
        Combination(s, 0, i);
    }

    return 0;
}