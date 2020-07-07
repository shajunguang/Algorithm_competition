#include<bits/stdc++.h>
using namespace std;
int v[16],le[16],ri[8],ans=0; //v负对角线，le正对角线，ri列
//按行搜索
void dfs(int r,int cur){
    if(cur==8){
        ans++;
        return;
    }
    for(int i=0;i<8;i++)
        if(!v[r+i] && !le[r-i+8] && !ri[i]){
            v[r+i]=le[r-i+8]=ri[i]=1;
            dfs(r+1,cur+1);
            v[r+i]=le[r-i+8]=ri[i]=0;
        }
}


int main()
{
    dfs(0,0);
    cout<<ans<<endl;
    return 0;
}