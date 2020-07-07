bool check(int x){} //检查x满足某种性质

//区间[l,r]被划分成[l,mid],[mid+1,r]：
int bsearch_1(int l,int r){
    while(l<r){
        int mid=l+r>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    return l;
}
//区间[l,r]被划分成[l,mid-1],[mid,r]：
int bsearch_2(int l,int r){
    while(l<r){
        int mid = l+r+1>>1; //注意这里加1，防止一直循环
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    return l;
}