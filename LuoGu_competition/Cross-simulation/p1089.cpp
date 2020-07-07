#include<bits/stdc++.h>
using namespace std;
int p1,p2,p3;

string op(char start, char end){
    string res;
    if(p1==1){
        if(p3==1)
            for(char i=start+1;i<end;i++)
                for(int j=1;j<=p2;j++)
                    res +=i;
        else
            for(char i=end-1;i>start;i--)
                for(int j=1;j<=p2;j++)
                    res +=i;
    }
    else if(p1==2){
        if(p3==1)
            for(char i=start+1;i<end;i++)
                for(int j=1;j<=p2;j++)
                    res +=isdigit(i)?i:i-32;
        else
            for(char i=end-1;i>start;i--)
                for(int j=1;j<=p2;j++)
                    res +=isdigit(i)?i:i-32;
    }
    else{
        for(char i=start+1;i<end;i++)
            for(int j=1;j<=p2;j++)
                res +='*';
    }
    return res;
}
int main()
{
    cin>>p1>>p2>>p3;
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
        if(s[i]=='-' && i!=0 && i!=s.size()-1)
            if((isdigit(s[i-1]) && isdigit(s[i+1])) || (isalpha(s[i-1]) && isalpha(s[i+1]))){
                if(s[i-1]==s[i+1]-1) s.erase(i,1);
                else if(s[i-1]<s[i+1]) s = s.substr(0,i)+op(s[i-1],s[i+1])+s.substr(i+1);
            }
    cout<<s<<endl;
    return 0;
}
/*
 * 总结下erase用法，erase(pos,count)删除位置和数量，如果没有count，默认删除到末尾
 * substr(start,end)截取start到end-1的字符串，没有end默认截取到末尾！！
 */
/*
 //这个即读即操作，以及for中用三元运算符有点秀
#include<bits/stdc++.h>
using namespace std;
int p1,p2,p3,i=0,k;
char ch[300],be,af,f,j,p;//p用于输出;
int main() {
    scanf("%d%d%d%s",&p1,&p2,&p3,ch);//输入;
    while(ch[i]){//当ch[i]有值时;
        be=ch[i-1];af=ch[i+1];f=ch[i];//f存储ch[i],便于判断;
        if(f=='-'&&af>be&&(be>='0'&&af<='9'||be>='a'&&af<='z')){//意思是ch[i]若为'-',就判断其前后是否满足条件，满足进入循环;
            for(p3==1?j=be+1:j=af-1; p3==1?j<af:j>be; p3==1?j++:j--){
                p=j;//j是整形变量，p是字符型变量，这样是将p赋值为ASCII码为j的字符;
                if(p1==2)//是否大写;
                    p=(p>='a')?p-32:p;//如果是字母就转成大写
                else if(p1==3) p='*';//是否输出'*'
                for(k=0; k<p2; k++)//输出p2个
                    printf("%c",p);
            }
        }
        else
            printf("%c",f);//如果ch[i]是非'-'或者其前后不满足条件，就原样输出;
        i++;//一定要放在后面，不然会出错QAQ;
    }
    return 0;
}
 */