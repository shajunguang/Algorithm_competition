#include<bits/stdc++.h>
using namespace std;
struct stu{
    int order;
    int Chinese;
    int total_score;
}st[305];
bool cmp(const stu &a,const stu &b){
    if(a.total_score!=b.total_score) return a.total_score>b.total_score;
    if(a.Chinese!=b.Chinese) return a.Chinese>b.Chinese;
    return a.order<b.order;
}
int main()
{
    int N,math,English;
    cin>>N;
    for(int i=1;i<=N;i++){
        st[i].order=i;
        cin>>st[i].Chinese>>math>>English;
        st[i].total_score=st[i].Chinese+math+English;
    }
    sort(st+1,st+N+1,cmp);
    for(int i=1;i<=5;i++) cout<<st[i].order<<" "<<st[i].total_score<<endl;
    return 0;
}