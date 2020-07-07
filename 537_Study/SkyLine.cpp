#include <bits/stdc++.h>
#define lf(x)   x<<1
#define rt(x)   x<<1|1
using namespace std;
const int MAXN = 1e5;
int st[MAXN*4+5],lazy[MAXN*4+5],ANS=0;

//线段树模板
void push_up(int root){
    if(lazy[lf(root)] && lazy[rt(root)] && st[lf(root)]==st[rt(root)]){
        lazy[root]=1;
        st[root]=st[lf(root)];
    }else{
        lazy[root]=st[root]=0;
    }
}
void build(int root,int l,int r){
    if(l==r) {
        lazy[root]=1;
        st[root]=0;
        return;
    }

    int m=l+r>>1;
    build(lf(root),l,m);
    build(rt(root),m+1,r);
    push_up(root);
}
//lazy标记
void push_down(int root){
    lazy[lf(root)]=lazy[rt(root)]=lazy[root];
    st[lf(root)]=st[rt(root)]=st[root];
    st[root]=lazy[root]=0;
}
int insert(int root,int l,int r,int ql, int qr, int h){
    if(lazy[root] && st[root]>h)    return 0;
    if(ql<=l && r<=qr && lazy[root]){
        st[root]=h;
        return r-l+1;
    }
    if(lazy[root])
        push_down(root);
    int m=l+r>>1,ret=0;
    if(m>=ql)   ret += insert(lf(root),l,m,ql,qr,h);
    if(m<qr)    ret += insert(rt(root),m+1,r,ql,qr,h);

    push_up(root);
    return ret;
}

int main()
{
    freopen("in.txt","r",stdin);
    int c,n,a,b,h;
    while(cin>>c && c){
        for(int _=0;_<c;_++){
            ANS=0;
            memset(st,0,sizeof st);
            memset(lazy,0,sizeof lazy);
            build(1,1,MAXN);
            cin>>n;
            for(int i=0;i<n;i++){
                cin>>a>>b>>h;
                ANS += insert(1,1,MAXN,a+1,b,h); //这里注意边界少一个
                //cout<<ANS<<endl;
            }
            cout<<ANS<<endl;
        }
    }

    return 0;
}