//使用两个栈来模拟队列
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void push(int node) {
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        st1.push(node);
    }

    void pop() {
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        int res=st2.top();
        st2.pop();
        cout<<res<<" ";
    }

private:
    stack<int> st1;
    stack<int> st2;
};
int main()
{
    Solution res;
    res.push(1);res.push(2);res.push(3);res.pop();res.pop();
    res.push(4);res.pop();res.push(5);res.pop();res.pop();
    return 0;
}