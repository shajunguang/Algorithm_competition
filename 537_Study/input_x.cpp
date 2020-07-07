#include<bits/stdc++.h>
char st[21][21];

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        int i=0,j=n-1,k=0;
        memset(st,0,sizeof st);
        while(i<j){
            st[k][i]='*';st[k][j]='*';
            i++,j--,k++;
        }
        while(i<n && j>=0){
            st[k][i]='*';st[k][j]='*';
            i++,j--,k++;
        }
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(st[i][j]=='*')printf("*");
                else printf(" ");
            }
            printf("\n");
        }
    }

    return 0;
}