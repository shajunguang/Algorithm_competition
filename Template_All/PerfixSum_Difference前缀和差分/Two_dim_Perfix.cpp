const int MAXN=1000;
int a[MAXN][MAXN],s[MAXN][MAXN];
for(int i=0;i<MAXN;i++)
    for(int j=0;j<MAXN;j++){
        s[i][j]=a[i][j];
        if(i) s[i][j]+=s[i-1][j];
        if(j) s[i][j]+=s[i][j-1];
        if(i&&j) s[i][j]-=s[i-1][j-1]; //s[i][j]=a[i][j]+s[i-1][j]+s[i][j-1]-s[i-1][j-1];
    }