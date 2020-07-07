#include"Stack.h"
char c[6]={'A','B','C','D','E','F'};
//应用一，二进制转为十进制
int bin2dec(sqStack *s,string &str){
    int t=0,j=1;
    initStack(s);
    for(auto i:str) Push(s,i); //指针记录首地址和位地址，和数组类似
    for(int i=0;i<(int)str.size();i++){
        t+=j*(*(--s->top)-'0');
        j*=2;
    }
    return t;
}
//二进制转为八进制,三位变为1位
string bin2oct(sqStack *s,string &str){
    string t;
    initStack(s);
    for(auto i:str) Push(s,i);
    ElemType e;
    for(int i=0;i<(int)str.size();){
        int j=0,m=0;
        while(j<3 && i<(int)str.size()){
            Pop(s,&e);
            m+=(e-'0')*pow(2,j);
            i++;
            j++;
        }
        t+='0'+m;
    }
    reverse(t.begin(),t.end());
    t='0'+t;
    return t;
}
//二进制转为16进制
string bin2hex(sqStack *s,string &str){
    string t;
    initStack(s);
    for(auto i:str) Push(s,i);
    ElemType e;
    for(int i=0;i<(int)str.size();){
        int j=0,m=0;
        while(j<4 && i<(int)str.size()){
            Pop(s,&e);
            m+=(e-'0')*pow(2,j);
            i++;
            j++;
        }
        if(m>=10) t+=c[m-10];
        else t+='0'+m;
    }
    reverse(t.begin(),t.end());
    t="0x"+t;
    return t;
}
//应用二,括号匹配
bool is_brackets(sqStack *s,string &str){
    initStack(s);
    if(str.empty()) return false;
    for(char i : str) {
        if(s->top==s->base){
            if(i=='(') Push(s,i);
            else return false;
        }else {
            ElemType e = *(s->top - 1);
            if (i != e) Pop(s, &e);
            else Push(s, i);
        }
    }
    return s->top == s->base;
}
//应用三 逆波兰表达式
int poland(sqStack*s,string str){
    initStack(s);
    int t=0;
    ElemType e,f;
    for(char i : str){
        if(i>='0' && i<='9') Push(s,i);
        else{
            Pop(s,&e);Pop(s,&f);
            switch (i){
                case '+':
                    t=e-'0'+(f-'0');
                    Push(s,t+'0');
                    break;
                case '-':
                    t=f-'0'-(e-'0');
                    Push(s,t+'0');
                    break;
                case '*':
                    t=(e-'0')*(f-'0');
                    Push(s,t+'0');
                    break;
                case '/':
                    t=(f-'0')/(e-'0');
                    Push(s,t+'0');
                    break;
                default:return -1;
            }
        }
    }
    return t;
}
//顺序表达式转为逆波兰表达式
//思路数字直接输出，符号，看与栈顶优先级，如果高就压栈，如果低或者是右括号
//依次出栈，知道遇到左括号或者栈空
string poland2s(sqStack *s,string str){
    initStack(s);
    string ans;
    for(int i=0;i<(int)str[i];i++){
        int f=0;
        while(isdigit(str[i])&&i<(int)str.size()) ans+=str[i],f=1,i++;
        if(f) ans+=" ";
        if(i<(int)str.size() && !isdigit(str[i])){
            if(!StackLen(*s)) Push(s,str[i]);
            else {
                ElemType e=*(s->top-1);
                if (str[i] == ')') {
                    while (StackLen(*s)) {
                        Pop(s,&e);
                        if(e=='(') break; //这里弹出的是括号的时候，不能打印！和下面区别开
                        ans+=e;
                        ans+=" ";
                    }
                }else if(str[i]=='-' || str[i]=='+'){
                    while(StackLen(*s)){
                        if(*(s->top-1)=='(') break; //这里需要注意，下一个是括号的时候，不能弹出
                        Pop(s,&e);
                        ans+=e;
                        ans+=" ";
                    }
                    Push(s,str[i]);
                }
                else if(str[i]=='*' || str[i]=='/'){
                    while(StackLen(*s)){
                        if(e=='(' || e=='+' || e=='-' ) break;
                        Pop(s,&e);
                        ans+=e;
                        ans+=" ";
                    }
                    Push(s,str[i]);
                }else Push(s,str[i]);
            }
        }
    }
    ElemType e;
    while(StackLen(*s)) Pop(s,&e),ans+=e,ans+=" "; //最后把剩余的运算全部加上
    //需要注意一点，剩下的一定是低优先级的，直接按出栈顺序打印即可
    return ans;
}


int main()
{
    sqStack s;
    string str="101010";
    cout<<bin2dec(&s,str)<<endl;
    cout<<bin2oct(&s,str)<<endl;
    cout<<bin2hex(&s,str)<<endl;
    Clear(&s);
    string s1="(((()()))";
    if(is_brackets(&s,s1)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    cout<<poland(&s,"45+12+/")<<endl;
    cout<<poland2s(&s,"1+1+(2+3)*5-3*2");
    return 0;
}