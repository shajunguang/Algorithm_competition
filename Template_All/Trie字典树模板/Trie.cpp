#include<bits/stdc++.h>
using namespace std;
int num=0;//顶点编号 
int tree[5000005][26];
int sum[5000005];//用于提问:给出以该字符串为前缀的单词的数量. 
int book[5000005];//book[i]表示节点i是否是一个单词的结尾，此题显然不用 
void insert(char s[])//建字典树 
{
    int now=0;//当前顶点编号 即根节点编号
    for(int i=0;i<strlen(s);i++){
        int id=s[i]-'a';//输入为全是小写的字符串
        if(!tree[now][id])//不存在就新建节点
            tree[now][id]=++num;
        now=tree[now][id];//当前顶点更新为上一个节点的孩子节点
        sum[now]++;//记录每一个节点访问次数
    }
    book[now]=1;//给结尾标记
    return;
}
int finds(char s[])
{
    int now=0;
    for(int i=0;i<strlen(s);i++){
        int id=s[i]-'a';
        if(tree[now][id])//当前节点不为空 即存在
        {
            now=tree[now][id];
        }
        else//不存在
            return 0;//不能作为每个词的前缀
    }
    return sum[now];
}
int main()
{
    int n;
    char s[12];
    //建树 
    while(gets(s)&&s[0]!='\0')//一个空行代表单词表的结束.
    {
        insert(s);
    }
    //查询
    while(gets(s))
    {
        printf("%d\n",finds(s));
    }
    return 0;
}