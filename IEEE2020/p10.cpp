#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
#define maxn 100000
#define eps 1e-8
struct Tree
{
    int left,right,num;//num记录这个区间被覆盖的次数 
    double len;//len记录这个区间被覆盖的长度 
}T[4*maxn];
struct Line
{
    double x,y1,y2;
    bool flag;
}line[maxn];
int n,cnt,res;
double y[maxn],ans,len;
bool equal(double x,double y)
{
    return fabs(x-y)<eps;
}
void add(double x,double y1,double y2,double yy,int flag)
{
    line[cnt].x=x;line[cnt].y1=y1;line[cnt].y2=y2;line[cnt].flag=flag;y[cnt++]=yy;
}
bool cmp(Line l1,Line l2)
{
    if(l1.x!=l2.x) return l1.x<l2.x;
    return l1.flag>l2.flag;
}
void build(int l,int r,int t)
{
    T[t].left=l;
    T[t].right=r;
    T[t].num=0;
    T[t].len=0;
    if(l+1==r)return ;
    int mid=(l+r)>>1;
    build(l,mid,2*t);
    build(mid,r,2*t+1);
}
void update_len(int t)
{
    if(T[t].num) T[t].len=y[T[t].right]-y[T[t].left];
    else if(T[t].left+1==T[t].right) T[t].len=0;
    else T[t].len=T[2*t].len+T[2*t+1].len;
}
void update(double l,double r,int t,int x)
{
    if(equal(y[T[t].left],l)&&equal(y[T[t].right],r)) T[t].num+=x;
    if(T[t].left+1<T[t].right)
    {
        int mid=(T[t].left+T[t].right)>>1;
        if(r<=y[mid]+eps) update(l,r,2*t,x);
        else if(l>=y[mid]-eps) update(l,r,2*t+1,x);
        else
        {
            update(l,y[mid],2*t,x);
            update(y[mid],r,2*t+1,x);
        }
    }
    update_len(t);
}
int main()
{
    while(cin>>n){
            cnt = 0;ans=0;len=0;
            int x1, x2, y1, y2;
            while (n--)
            {
                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
                if(x1==x2 && y1==y2) x1--,y1--;
                else if (x2 >= x1 && y2 >= y1) x1--, y1--, swap(x1, x2);
                else if (x2 <= x1 && y2 <= y1) x2--, y2--, swap(y1, y2);
                else if (x2 > x1 && y2 < y1) x1--, y2--, swap(x1, x2), swap(y1, y2);
                else if (x2 < x1 && y2 > y1) y1--, x2--;
                //将每个矩形用左右两边表示
                add(x1, y1, y2, y1, 1);
                add(x2, y1, y2, y2, 0);
            }
            sort(line, line+cnt, cmp);//对得到的线段按x升序排序
            //对y轴建树
            sort(y, y+cnt);
            res=unique(y, y+cnt)-y;
            build(0, res-1, 1);
            for (int i=0;i<cnt;i++)
            {
                if (line[i].flag) update(line[i].y1, line[i].y2, 1, 1);//扫到左边的边就在线段树中覆盖这部分
                else update(line[i].y1, line[i].y2, 1, -1);//扫到右边的边就在线段树中取消这部分的覆盖
                if (i) ans += len * (line[i].x - line[i - 1].x);//累加每次扫描线扫过的面积
                len = T[1].len;//维护扫描线上被覆盖的长度
            }
            cout<<ans<<endl;
    }

    return 0;
}