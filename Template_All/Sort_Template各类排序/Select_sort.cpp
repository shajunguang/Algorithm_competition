#include<bits/stdc++.h>
using namespace std;
template <typename comparable>
void Selectsort(vector<comparable> &a){
    for(int i=0;i<a.size();i++){
        int minid=i; //记录最小值的位置
        for(int j=i+1;j<a.size();j++)
            if(a[j]<a[minid]){
                minid=j;
            }
        swap(a[i],a[minid]); //交换最小值的值到第i个
    }
}