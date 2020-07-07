//邻接表
#include<bits/stdc++.h>
using namespace std;
const int MAXN=100; //最大节点个数

typedef struct LinkList{
    int val;
    LinkList* next;
}*LinkPtr;

struct LinkGraph{
    LinkPtr head=NULL,rear=NULL;
}graph[MAXN];

void connect(int a,int b){
    auto t=(LinkPtr)malloc(sizeof(LinkList));
    t->val=b;
    if(graph[a].head==NULL) {
        graph[a].head = (LinkPtr) malloc(sizeof(LinkList));
        graph[a].head->val = a;

        graph[a].head->next = t;
        t->next = NULL;
        graph[a].rear=t;
    }else{
        graph[a].rear->next=t;
        t->next=NULL;
        graph[a].rear=t;
    }
}
//初始化图
void initGraph(){
    int n;cin>>n;
    while(n--) {
        int a, b;
        cin >> a >> b;
        connect(a,b);
        connect(b,a);
    }
}

int main()
{
    initGraph();
    cout<<graph[0].rear->val<<endl;
    return 0;
}