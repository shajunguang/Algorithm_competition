#include<bits/stdc++.h>
using namespace std;
template <typename comparable>
void Shellsort(vector<comparable> &a){ //其实就是间隔版的插入排序
    //利用性质，大间隔排好序,小间隔排序时不会影响大间隔排序,牛！时间也快起来了
    for(int gap=a.size()/2;gap>0;gap/=2)
        for(int j=gap;j<a.size();j++){ //下面就是插入排序套路
            auto key=a[j];
            int i=j-gap; //跳gap排序,比如a[0] a[gap]
            while(i>=0 && a[i]>key){
                a[i+gap]=a[i]; //a[j]=a[0]
                i-=gap; //每次减少gap i=-gap;
            }
            a[i+gap]=key; //最后插入key,a[0]=a[j]
        }
}