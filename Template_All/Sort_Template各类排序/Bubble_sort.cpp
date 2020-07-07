#include<bits/stdc++.h>
using namespace std;
template<typename comparable>
void Bubblesort(vector<comparable> &a){
    int flag=1; //记录是否比较
    for(int i=0;flag;i++){ //上次冒泡没有比较过,就跳出循环
        flag=0;
        for(int j=a.size()-1;j>i;j--)
            if(a[j]<a[j-1]){ //这里注意是小于,保证稳定排序
                swap(a[j],a[j-1]);
                flag=1;
            }
    }
}