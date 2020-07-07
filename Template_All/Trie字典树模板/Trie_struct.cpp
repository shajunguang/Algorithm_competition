//结构体的字典树版本，时间复杂度，建树O(mn) (m表示字符串长度，n表示字符串数量）
//查询时间 O(mt) t表示查询次数
#include<bits/stdc++.h>
using namespace std;

struct Trie{
    bool is_end=false;
    Trie* son[26];
    Trie(){
        is_end=false;
        for(int i=0;i<26;i++) son[i]=NULL;
    }
}*root;

void insert(string s){
    auto p=root;
    for(auto c:s){
        int u=c-'a';
        if(p->son[u]==NULL) p->son[u]=new Trie();
        p=p->son[u];
    }
    p->is_end=true;
}
bool find_word(string s){
    auto p=root;
    for(auto c:s){
        int u=c-'a';
        if(p->son[u]==NULL) return false;
        p=p->son[u];
    }
    return p->is_end;
}
bool find_prefix(string s){
    auto p=root;
    for(auto c:s){
        int u=c-'a';
        if(p->son[u]==NULL) return false;
        p=p->son[u];
    }
    return true;
}
int main()
{
    root=new Trie();
    insert("abc");insert("cde");insert("cdf");
    if(find_word("cdf"))cout<<1<<endl;
    if(find_prefix("cd")) cout<<1<<endl;
    return 0;

}