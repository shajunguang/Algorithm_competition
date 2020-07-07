//采花生
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
vector<PII> pos;
const int MAXN=25;
int Map[MAXN][MAXN];
bool cmp(PII& a, PII& b){
    if(a.first==b.first) return a.second<b.second;
    return a.first >b.first;
}

int main()
{
    int M,N,K;
    cin>>M>>N>>K;
    for(int i=0;i<M;i++)
        for(int j=0;j<N;j++){
            cin>>Map[i][j];
            if(Map[i][j]) pos.emplace_back(make_pair(Map[i][j], i*N+j));
        }
    sort(pos.begin(),pos.end(),cmp);
    int time=0,back=0,ans=0,count=0;//当前所花时间和返回时间
    while(time+back<K && count<pos.size()){
        int tx=pos[0].second/N,ty=pos[0].second%N;
        for(auto i:pos){
            if(!time) time +=i.second/N+2;
            else time += abs(i.second/N-tx)+abs(i.second%N-ty)+1;
            back =i.second/N+1;
            if(time+back<=K) ans += i.first,count++;
            else break;
            tx=i.second/N,ty=i.second%N;
        }
    }
    cout<<ans<<endl;
    return 0;
}