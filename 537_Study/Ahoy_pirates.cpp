#include <bits/stdc++.h>
using namespace std;
#define local
#define left(x) x<<1
#define right(x) (x<<1)+1
using namespace std;
const int FLAG=-1e9;
const int MAXN=1e6;
int st[MAXN<<2],lazy[MAXN<<2];
//char op[4]={'F','E','I','S'};
string s;

//线段树模板
int build(int root ,int l,int r){	//range sum  tree simplest case
    if(l==r)return st[root]=s[l]-'0';
    int m=l+(r-l)/2;	//注意 求中值最好用我这里的写法 尽量不要用  m=(l+r)/2
    int lv=build(left(root),l,m);
    int rv=build(right(root),m+1,r);
    return st[root]=lv+rv;	//注意  不同类型线段树这里的操作不一样
}
//一般更新,区间变为0或者1
int lazy_update(int root,int l,int r,int ql,int qr,int val){
    if(lazy[root]==val) {
        st[root] = lazy[root] * (r - l + 1);
        lazy[left(root)] = lazy[root];    //lazy propagation
        lazy[right(root)] = lazy[root];    //lazy propagation
        lazy[root] = FLAG;
    }else if(lazy[root]==2) {
        st[root] = (r - l + 1)-st[root];
        if(lazy[left(root)]==FLAG) lazy[left(root)]=lazy[root];
        else if(lazy[left(root)]==0) lazy[left(root)]=1;
        else if(lazy[left(root)]==1) lazy[left(root)]=0;
        if(lazy[right(root)]==FLAG) lazy[right(root)]=lazy[root];
        else if(lazy[right(root)]==0) lazy[right(root)]=1;
        else if(lazy[right(root)]==1) lazy[right(root)]=0;
        lazy[root] = FLAG;
    }
    if(l>=ql && r<=qr){
        lazy[root]=val;
        return val*(r-l+1);
    }
    if(r<ql || l>qr)return st[root];
    int m=l+(r-l)/2;
    int lv=lazy_update(left(root),l,m,ql,qr,val);
    int rv=lazy_update(right(root),m+1,r,ql,qr,val);
    return st[root]=lv+rv;
}
//特殊更新,区间进行反转
int lazy_update_special(int root,int l,int r,int ql,int qr){
    if(lazy[root]==2) {
        st[root] = (r - l + 1)-st[root];
        if(lazy[left(root)]==FLAG) lazy[left(root)]=lazy[root];
        else if(lazy[left(root)]==0) lazy[left(root)]=1;
        else if(lazy[left(root)]==1) lazy[left(root)]=0;
        if(lazy[right(root)]==FLAG) lazy[right(root)]=lazy[root];
        else if(lazy[right(root)]==0) lazy[right(root)]=1;
        else if(lazy[right(root)]==1) lazy[right(root)]=0;
        lazy[root] = FLAG;
    }else if(lazy[root]==0 || lazy[root]==1){
        st[root]=lazy[root]*(r-l+1);
        lazy[left(root)]=lazy[root];
        lazy[right(root)]=lazy[root];
        lazy[root]=FLAG;
    }
    if(l>=ql && r<=qr){
        lazy[root]=2;
        return (r-l+1)-st[root];
    }
    if(r<ql || l>qr)return st[root];
    int m=l+(r-l)/2;
    int lv=lazy_update_special(left(root),l,m,ql,qr);
    int rv=lazy_update_special(right(root),m+1,r,ql,qr);
    return st[root]=lv+rv;
}
int lazy_query(int root,int l,int r,int ql,int qr){
    if(lazy[root]==0 || lazy[root]==1){
        st[root]=lazy[root]*(r-l+1);
        lazy[left(root)]=lazy[root];
        lazy[right(root)]=lazy[root];
        lazy[root]=FLAG;
    }
    else if(lazy[root]==2){
        st[root] = (r - l + 1)-st[root];
        if(lazy[left(root)]==FLAG) lazy[left(root)]=lazy[root];
        else if(lazy[left(root)]==0) lazy[left(root)]=1;
        else if(lazy[left(root)]==1) lazy[left(root)]=0;
        if(lazy[right(root)]==FLAG) lazy[right(root)]=lazy[root];
        else if(lazy[right(root)]==0) lazy[right(root)]=1;
        else if(lazy[right(root)]==1) lazy[right(root)]=0;
        lazy[root] = FLAG;
    }
    if(l>=ql && r<=qr)return st[root];
    if(r<ql || l>qr)return 0;//注意 不同类型线段树这里的操作不一样
    int m=l+(r-l)/2;
    int lv=lazy_query(left(root),l,m,ql,qr);
    int rv=lazy_query(right(root),m+1,r,ql,qr);
    return lv+rv;
}
int main()
{
#ifdef local
    freopen("in.txt","r",stdin);
#endif
    int n,m,t,Case=1;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            string temp;
            cin>>t>>temp;
            for(int j=0;j<t;j++)    s +=temp;
        }
        int s_s = s.size()-1;
        //初始化lazy数组，抄板子漏掉这个，吐了
        for(int i=0;i<4*MAXN;i++)lazy[i]=FLAG;
        memset(st,0,sizeof st);
        build(1,0,s_s); //直接用海盗字符串建立线段树
        int op_n,l,r,Case1=1;
        char c;
        scanf("%d",&op_n);
        printf("Case %d: \n",Case++);
        for(int i=0;i<op_n;i++){
            cin>>c>>l>>r;
            if(c=='F')
                lazy_update(1,0,s_s,l,r,1);
            else if(c=='E')
                lazy_update(1,0,s_s,l,r,0);
            else if(c=='I')
                lazy_update_special(1,0,s_s,l,r);
            else if(c=='S')
            {
                int ans = lazy_query(1,0,s_s,l,r);
                printf("Q%d: %d\n",Case1++,ans);
            }
        }
        s.clear(); //清空原数组
    }
    return 0;
}