//计算全排列
#include<bits/stdc++.h>
using namespace std;

void Permutation(char* s,int n){ //stl方法
    do{
        cout<<s<<endl;
    }while(next_permutation(s,s+n));
}
int ans=0;
void Permutation1(char* pStr,char* pBegin){//回溯方法
    assert(pStr && pBegin);

    if(*pBegin=='\0') {
        ans++;
        printf("%s\n",pStr);
        return;
    }

    for(char* t=pBegin;*t!='\0';t++){ //注意这里从pBegin开始，避免重复答案
        swap(*pBegin,*t); //注意一点这里交换的是指针对应的值
        Permutation1(pStr,pBegin+1);
        swap(*pBegin,*t);//回溯
    }
}
//考虑重复的
bool isSwap(char* pBegin,char* pEnd){
    for(char* t=pBegin;t<pEnd;t++)
        if(*t==*pEnd) return false;

    return true;
}
void Permutation2(char* pStr,char* pBegin){//回溯方法
    assert(pStr && pBegin);

    if(*pBegin=='\0') {
        ans++;
        printf("%s\n",pStr);
        return;
    }

    for(char* t=pBegin;*t!='\0';t++)//注意这里从pBegin开始，避免重复答案
        if(isSwap(pBegin,t)){
            swap(*pBegin, *t); //注意一点这里交换的是指针对应的值
            Permutation2(pStr, pBegin + 1);
            swap(*pBegin, *t);//回溯
        }
}
bool isSwap(string s,int l,int r){ //这里很关键,是从l到r出现重复,即不能交换
    //可以理解为交换后以是s[r]位置出现重复结果
    for(int i=l;i<r;i++) if(s[i]==s[r]) return false;

    return true;
}

vector<string> res;
void dfs(string &s, int left){
    if(left==s.size()) res.emplace_back(s);
    for(int i=left; i<s.size(); ++i){
        if(isSwap(s,left,i)) {
            swap(s[i], s[left]);
            dfs(s, left + 1);
            swap(s[i], s[left]);
        }
    }
}

int main()
{
    char s[5]="aacc";
    string s1="aacc";
    dfs(s1,0);
    Permutation2(s,s);
    cout<<ans<<endl;
    return 0;
}