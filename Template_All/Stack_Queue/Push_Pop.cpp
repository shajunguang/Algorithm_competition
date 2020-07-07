//根据压栈顺序判断出栈顺序是否合理
#include<bits/stdc++.h>
using namespace std;
bool IsPopOrder(vector<int> pushV,vector<int> popV) {
    if(pushV.size() == 0) return false;
    vector<int> stack; //这里借助外部存储
    for(int i = 0,j = 0 ;i < pushV.size();){
        stack.push_back(pushV[i++]);
        while(j < popV.size() && stack.back() == popV[j]){
            stack.pop_back();
            j++;
        }
    }
    return stack.empty();
}
int main()
{
    vector<int>push={1,2,3,4,5};
    vector<int>pop={4,5,3,2,1};
    if(IsPopOrder(push,pop)) cout<<"True";
    else cout<<"False";
    return 0;
}