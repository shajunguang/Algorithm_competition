bool check(int x){} //检查x满足某种性质

double bsearch_3(double l, double r){
    const double eps=1e-6; // eps表示精度，取决于题目
    while(r-l>eps){
        double mid = (l+r)/2;
        if(check(mid)) r=mid;
        else l = mid;
    }
    return l;
}