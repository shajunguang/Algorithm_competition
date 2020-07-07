//括号匹配问题，栈解决
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int c,f=1;
    stack<char> s;
    while(c=getchar()){
        if(c=='@')break;
        if(c=='(') s.push(c);
        if(c==')'){
            if(s.empty()) {f=0;break;}
            s.pop();
        }
    }
    if(s.empty() && f!=0) cout<<"YES";
    else cout<<"NO";
    return 0;
}