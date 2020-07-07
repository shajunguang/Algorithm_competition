#include<bits/stdc++.h>
using namespace std;
const int MAXN=2000;
string ans[MAXN];
void add(int end){
    for(int i=end;i<(end<<1);i++) ans[i]=ans[i-end]+ans[i-end];//向下复制两个
    for(int i=0;i<end;i++){
        ans[i].insert(0,end,' ');
        ans[i].insert(ans[i].size(),end,' ');
    }
}
int main()
{
    int n;scanf("%d",&n);
    ans[0]=" /\\ ";
    ans[1]="/__\\";
    for(int i=1;i<n;i++)add(1<<i);
    for(int i=0;i<(1<<n);i++)cout<<ans[i]<<endl;
    return 0;
}