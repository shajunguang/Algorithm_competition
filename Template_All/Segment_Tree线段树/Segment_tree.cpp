#include <bits/stdc++.h>
#define left(x) x<<1
#define right(x) (x<<1)+1
using namespace std;
const int FLAG=-1e9;
const int MAXN=1e5;
int st[MAXN*4];//注意root是从1开始！不是0

int build(int root ,int l,int r,int A[]){	//range sum  tree simplest case
    if(l==r)return st[root]=A[l];
    int m=l+(r-l)/2;	//注意 求中值最好用我这里的写法 尽量不要用  m=(l+r)/2
    int lv=build(left(root),l,m,A);
    int rv=build(right(root),m+1,r,A);
    return st[root]=lv+rv;	//注意  不同类型线段树这里的操作不一样
}
int query(int root,int l,int r,int ql,int qr){
    if(l>=ql && r<=qr)return st[root];
    if(r<ql ||l>qr)return 0;	//注意 不同类型线段树这里的操作不一样
    int m=l+(r-l)/2;
    int lv=query(left(root),l,m,ql,qr);
    int rv=query(right(root),m+1,r,ql,qr);
    return lv+rv;	//注意  不同类型线段树这里的操作不一样
}
int update(int root ,int l,int r,int ql ,int qr,int val){	//复杂度注意为nlogn 需要更高的区间修改复杂度需要用
//lazy propagation
    if(l==r && (l>=ql) && (r<=qr))
    {
        // cerr<<"des "<<l<<" "<<r<<endl;
        return st[root]=val;
    }
    if(r<ql || l>qr)return st[root];//注意 不同类型线段树这里的操作不一样
    int m=l+(r-l)/2;
    int lv=update(left(root),l,m,ql,qr,val);
    int rv=update(right(root),m+1,r,ql,qr,val);
    // cerr<<"range update "<<l<<" "<<r<<" "<<val<<endl;
    return st[root]=lv+rv;	//注意  不同类型线段树这里的操作不一样
}
// interesting
int lazy[MAXN*8];	//注意这里是最大节点数乘以8 ，其实可以乘以4，但是为了编程方便， 在空间允许
//的情况下直接乘8
int lazy_update(int root,int l,int r,int ql,int qr,int val){
    if(lazy[root]!=FLAG){//lazy propagation最大的不同是使用了懒标签.
        st[root]=lazy[root]*(r-l+1);//lazy propagation 的其中一个难点，这里怎么更新 假如这里
        //是 range max query tree 呢
        lazy[left(root)]=lazy[root];	//lazy propagation
        lazy[right(root)]=lazy[root];	//lazy propagation
        lazy[root]=FLAG;
    }
    if(l>=ql && r<=qr){

        lazy[root]=val;	//懒惰传播的关键在这里！ 打个懒标签就不走了
        return (r-l+1)*val;	//注意这里的返回值！
    }
    if(r<ql || l>qr)return st[root];
    int m=l+(r-l)/2;
    int lv=lazy_update(left(root),l,m,ql,qr,val);
    int rv=lazy_update(right(root),m+1,r,ql,qr,val);
    return st[root]=lv+rv;
}
int lazy_query(int root,int l,int r,int ql,int qr){
    if(lazy[root]!=FLAG){	//注意 lazy query就是这里多了这个东西，我们每次都必须把懒标签往下传
        st[root]=lazy[root]*(r-l+1);//lazy propagation 的其中一个难点，这里怎么更新 假如这里
        //是 range max query tree 呢
        lazy[left(root)]=lazy[root];
        lazy[right(root)]=lazy[root];
        lazy[root]=FLAG;
    }
    if(l>=ql && r<=qr)return st[root];
    if(r<ql || l>qr)return 0;//注意 不同类型线段树这里的操作不一样
    int m=l+(r-l)/2;
    int lv=lazy_query(left(root),l,m,ql,qr);
    int rv=lazy_query(right(root),m+1,r,ql,qr);
    return lv+rv;
}
int main(){
    int A[]={1,2,3,4,5};
    build(1,0,4,A);

    int ans=query(1,0,4,0,1);
    cerr<<"query 0 1 sum 1+2= "<<ans<<endl;
    ans=query(1,0,4,0,0);
    cerr<<"query 0 0 sum 1= "<<ans<<endl;
    ans=query(1,0,4,0,4);
    cerr<<"query 0 4 sum 1+2+3+4+5= "<<ans<<endl;
    update(1,0,4,0,3,2);
    cerr<<"update 1,2,3,4,5-> 2 2 2 2 5"<<endl;
    ans=query(1,0,4,0,4);
    cerr<<"query sum 2+2+2+2+5: "<<ans<<endl;

    for(int i=0;i<8*MAXN;i++)lazy[i]=FLAG;
    ans=lazy_query(1,0,4,0,4);
    cerr<<"lazy query sum 2+2+2+2+5: "<<ans<<endl;

    lazy_update(1,0,4,0,0,1);
    cerr<<"lazy update -> 1 2 2 2 5"<<endl;
    ans=lazy_query(1,0,4,0,0);
    cerr<<"lazy query sum 1: "<<ans<<endl;
    ans=lazy_query(1,0,4,0,4);
    cerr<<"lazy query sum 1+2+2+2+5: "<<ans<<endl;

    lazy_update(1,0,4,0,3,1);
    cerr<<"lazy update -> 1 1 1 1 5"<<endl;
    ans=lazy_query(1,0,4,0,0);
    cerr<<"lazy query sum 1: "<<ans<<endl;
    ans=lazy_query(1,0,4,0,4);
    cerr<<"lazy query sum 1+1+1+1+5: "<<ans<<endl;

    lazy_update(1,0,4,0,1,3);
    lazy_update(1,0,4,0,0,5);
    ans=lazy_query(1,0,4,0,4);
    cerr<<"lazy query sum 5+3+1+1+5: "<<ans<<endl;

    return 0;
}
