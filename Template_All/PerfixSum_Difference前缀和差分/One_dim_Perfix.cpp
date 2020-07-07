const int MAXN=1000; //数组大小
int a[MAXN],s[MAXN];
for(int i=0;i<MAXN;i++){
    s[i]=a[i];
    if(i) s[i]+=s[i-1]; //a[i]+s[i-1]
}