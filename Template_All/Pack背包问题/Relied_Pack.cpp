/*
dfs在遍历到 x 结点时，先考虑一定选上根节点 x ，因此初始化 f[x][v[x] ~ m] = w[x]
在分组背包部分：
j 的范围 [ m , v[x] ] 小于v[x]则没有意义因为连根结点都放不下；
k 的范围 [ 0 , j-v[x] ]，当大于j-v[x]时分给该子树的容量过多，剩余的容量连根节点的物品都放不下了；
 */

#include<iostream>
#include<vector>
using namespace std;
int f[110][110];//f[x][v]表达选择以x为子树的物品，在容量不超过v时所获得的最大价值
vector<int> g[110];
int v[110],w[110];
int n,m,root;

void dfs(int x)
{
    for(int i=v[x];i<=m;i++) f[x][i]=w[x];//点x必须选，所以初始化f[x][v[x] ~ m]= w[x]
    for(int i=0;i<g[x].size();i++)
    {
        int y=g[x][i];
        dfs(y);
        for(int j=m;j>=v[x];j--)//j的范围为v[x]~m, 小于v[x]无法选择以x为子树的物品
        {
            for(int k=0;k<=j-v[x];k++)//分给子树y的空间不能大于j-v[x],不然都无法选根物品x
            {
                f[x][j]=max(f[x][j],f[x][j-k]+f[y][k]);
            }
        }
    }
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int fa;
        cin>>v[i]>>w[i]>>fa;
        if(fa==-1)
            root=i;
        else
            g[fa].push_back(i);
    }
    dfs(root);
    cout<<f[root][m];
    return 0;
}
/*
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int N = 110;
int n,m;
int h[N],e[N],ne[N],idx;
//h数组是邻接表的头它的下表是当前节点的标号，
 值是当前结点第一条边的编号（其实是最后加入的那一条边），
 e数组是边的集合，它的下标是当前边的编号，数值是当前边的终点；
//ne是nextedge，如果ne是-1表示当前结点没有下一条边，
 ne的下标是当前边的编号，数值是当前结点的下一条边的编号，idx用于保存每一条边的上一条边的编号。
//这样我们就知道了当前结点的第一条边是几，这个边的终点是那个结点，
 该节点的下一条边编号是几，那么邻接表就完成了
int v[N],w[N],f[N][N];

void add(int a,int b){
    e[idx] = b,ne[idx] = h[a],h[a] = idx++;
    //该方法同于向有向图中加入一条边，这条边的起点是a，终点是b，加入的这条边编号为idx
}

void dfs(int u){
    for(int i = h[u];i!=-1;i = ne[i]){//对当前结点的边进行遍历
        int son = e[i];//e数组的值是当前边的终点，即儿子结点
        dfs(son);
        for(int j = m-v[u];j>=0;j--){
            //遍历背包的容积，因为我们是要遍历其子节点，所以当前节点我们是默认选择的。
            //这个时候当前结点我们看成是分组背包中的一个组，
            //子节点的每一种选择我们都看作是组内一种物品，所以是从大到小遍历。
            //我们每一次都默认选择当前结点，因为到最后根节点是必选的。
            for(int k = 0;k<=j;k++){//去遍历子节点的组合
                f[u][j] = max(f[u][j],f[u][j-k]+f[son][k]);
            }
        }
    }
    //加上刚刚默认选择的父节点价值
    for(int i = m;i>=v[u];i--){
        f[u][i] = f[u][i-v[u]]+w[u];
    }
    //因为我们是从叶子结点开始往上做，
    //所以如果背包容积不如当前物品的体积大，那就不能选择当前结点及其子节点，因此赋值为零
    for(int i = 0;i<v[u];i++){
        f[u][i] = 0;
    }
}

int main(){
    memset(h,-1,sizeof h);
    cin>>n>>m;
    int root;
    for(int i = 1;i<=n;i++){
        int p;
        cin>>v[i]>>w[i]>>p;
        if(p==-1){
            root = i;
        }else{
            add(p,i);//如果不是根节点就加入邻接表,其中p是该节点的父节点，i是当前是第几个节点
        }
    }
    dfs(root);
    cout<<f[root][m]<<endl;
    return 0;
}

*/
