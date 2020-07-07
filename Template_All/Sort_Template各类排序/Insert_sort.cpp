#include<bits/stdc++.h>
using namespace std;
template <typename comparable>
void Insertsort(vector<comparable> &a){
    for(int j=1;j<a.size();j++){
        auto key = a[j]; //待插元素
        int i=j-1;
        while(i>=0 && a[i]>key){ //这里用>保证稳定性
            a[i+1]=a[i]; //比a[j]大的后面凉快去！
            i--;
        }
        a[i+1]=key; //最后把key换到正确的位置
    }
}