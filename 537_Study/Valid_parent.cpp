#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkValidString(string s) {
        stack<char> st;
        int sp=0;
        for(auto c:s){
            if(c==')'){
                if(st.empty()) return false;
                sp=0;
                while(!st.empty() && st.top()!='(') {
                    sp++;
                    st.pop();
                }
                if(st.empty()){
                    for(int i=0;i<sp-1;i++) st.push('*');
                }else{
                    st.pop();
                    for(int i=0;i<sp;i++) st.push('*');
                }
            }else st.push(c);
        }
        sp=0;
        while(!st.empty()){
            char c=st.top();st.pop();
            if(c=='*') sp++;
            if(c=='(') {
                if(sp==0) return false;
                else sp--;
            }
        }
        return true;
    }
};

int main()
{
    string s="*()(())*()(()()((()(()()*)(*(())((((((((()*)(()(*)";
    Solution res;
    res.checkValidString(s);

    return 0;
}