/*
请你来实现一个 atoi 函数，使其能将字符串转换成整数。
 思路：先把答案字符串提炼出来，如果为空返回0，这里有几点需要注意：
 1.+-空格三个再次在数字出现后，再出现就应该跳出循环，打标记即可
 2.前置0，也是一样，直到出现非0数字前，都不加，之后打上标记，可加
 */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int myAtoi(string str) {
        string res;
        int t=1,f=1,f1=1; //f是跳出标记，f1为前置0标记
        for(auto c:str){
            if(c!=' '){
                if(f && c=='-') f=0,t=-1;
                else if(f && c=='+') f=0;
                else if(isdigit(c)){
                    f=0;
                    if(f1 && c!='0') f1=0;
                    if(!f1) res+=c;
                }
                else break;
            }else if(!f) break;
        }
        if(res.empty()) return 0;
        if(res.size()>12) return t==1?INT_MAX:INT_MIN;
        stringstream ss;
        ss<<res;
        long long ans;
        ss>>ans;
        ans*=t;
        if(ans<INT_MIN) return INT_MIN;
        if(ans>INT_MAX) return INT_MAX;
        return ans;
    }
};
//这个写法更简洁，秒啊，看题解就是爽,在计算过程中跳出，真的骚
class Solution_1 {
public:
    int myAtoi(string str) {
        int i = 0, flag = 1;
        long res = 0; //默认flag = 1，正数
        while (str[i] == ' ') i ++; //若str全为空格，str[i] = '\0'(最后一个i)
        if (str[i] == '-') flag = -1;
        if (str[i] == '-' || str[i] == '+') i ++;
        for (; i < str.size() && isdigit(str[i]); i ++)  {
            res = res * 10 + (str[i] - '0');
            if (res >= INT_MAX && flag == 1) return  INT_MAX;
            if (res > INT_MAX && flag == -1) return  INT_MIN;
        }
        return flag * res;
    }
};
//再贴个有限状态机(DFA)
class Automaton {
    string state = "start";
    unordered_map<string, vector<string>> table = {
            {"start", {"start", "signed", "in_number", "end"}},
            {"signed", {"end", "end", "in_number", "end"}},
            {"in_number", {"end", "end", "in_number", "end"}},
            {"end", {"end", "end", "end", "end"}}
    };

    int get_col(char c) {
        if (isspace(c)) return 0;
        if (c == '+' or c == '-') return 1;
        if (isdigit(c)) return 2;
        return 3;
    }
public:
    int sign = 1;
    long long ans = 0;

    void get(char c) {
        state = table[state][get_col(c)];
        if (state == "in_number") {
            ans = ans * 10 + c - '0';
            ans = sign == 1 ? min(ans, (long long)INT_MAX) : min(ans, -(long long)INT_MIN);
        }
        else if (state == "signed")
            sign = c == '+' ? 1 : -1;
    }
};

class Solution_2 {
public:
    int myAtoi(string str) {
        Automaton automaton;
        for (char c : str)
            automaton.get(c);
        return automaton.sign * automaton.ans;
    }
};