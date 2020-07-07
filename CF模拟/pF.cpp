/*
#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e3+5;
struct env{
    int order;
    int w;
    int h;
}a[MAXN];
bool cmp(const env &b,const env &c){
    return b.w<c.w && b.h<c.h;
}

int main()
{
    int n,w0,h0;
    cin>>n>>w0>>h0;
    for(int i=1;i<=n;i++) {
        cin >> a[i].w >> a[i].h;
        a[i].order=i;
    }
    sort(a+1,a+n+1,cmp);
    int max=0;
    vector<int> ans;
    for(int i=1;i<=n;i++){
        int w1=a[i].w,h1=a[i].h,count=0;
        vector<int>temp;
        if(w1>w0 && h1>h0){
            count++;
            temp.push_back(a[i].order);
            for(int j=i+1;j<=n;j++)
                if(a[j].w>w1 && a[j].h>h1){
                    count++;
                    temp.push_back(a[j].order);
                    w1=a[j].w,h1=a[j].h;
                }
        }
        if(count>max){
            ans.clear();
            max=count;for(auto t:temp) ans.push_back(t);
        }
    }
    if(max){
        cout<<max<<endl;
        for(auto i:ans)cout<<i<<" ";
    }else cout<<0<<endl;
    return 0;
}
 */
#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e3+5;
struct env{
    int order;
    int w;
    int h;
}a[MAXN];
bool cmp(const env &b,const env &c){
    if(b.w==c.w) return b.h<c.h;
    return b.w<c.w;
}
int main()
{
    int n,w0,h0;
    cin>>n>>w0>>h0;
    for(int i=1;i<=n;i++) {
        cin >> a[i].w >> a[i].h;
        a[i].order=i;
    }
    sort(a+1,a+n+1,cmp);
    vector<vector<env>> c;
    for(int i=1;i<n;i++){
        vector<env> temp;
        temp.push_back(a[i]);
        int h1=a[i].h,w1=a[i].w;
        for(int j=i+1;j<=n;j++)
            if(a[j].w>w1 && a[j].h>h1){
                temp.push_back(a[j]);
                w1=a[j].w,h1=a[j].h;
            }
        c.push_back(temp);
    }
    int max=0,pos=0;
    for(int i=0;i<c.size();i++)
        if(c[i][0].w>w0 && c[i][0].h>h0)
            if(c[i].size()>max) max=c[i].size(),pos=i;
    if(max){
        cout<<max<<endl;
        for(auto i:c[pos]) cout<<i.order<<" ";
    }else cout<<0<<endl;
    return 0;
}