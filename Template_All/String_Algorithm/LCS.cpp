#include <bits/stdc++.h>
using namespace std;

char a[500],b[500];
char num[501][501]; ///记录中间结果的数组
char flag[501][501];    ///标记数组，用于标识下标的走向，构造出公共子序列

void LCS()///动态规划求解
{
    for(int i=1;i<=strlen(a);i++)
        for(int j=1;j<=strlen(b);j++)
        {
            if(a[i-1]==b[j-1])   ///注意这里的下标是i-1与j-1
                num[i][j]=num[i-1][j-1]+1,flag[i][j]=1;  ///斜向下标记
            else if(num[i][j-1]>num[i-1][j])
                num[i][j]=num[i][j-1], flag[i][j]=2;  ///向右标记
            else
                num[i][j]=num[i-1][j], flag[i][j]=3;  ///向下标记
        }
}

void getLCS()  ///采用倒推方式求最长公共子序列
{
    char res[500],pnt=0; ///pnt用于保存结果的数组标志位
    for(int i=strlen(a),j=strlen(b);  i>0&&j>0 ; )
    {
        if(flag[i][j]==1) res[pnt++]=a[i-1],i--,j--;  ///如果是斜向下标记
        else if(flag[i][j]==2) j--; ///如果是斜向右标记
        else if(flag[i][j]==3) i--; ///如果是斜向下标记
    }
    for(int i=pnt-1;i>=0;i--)
        printf("%c",res[i]);
}
int main()
{
    int i;
    strcpy(a,"ABCBDAB");
    strcpy(b,"BDCABA");
    memset(num,0,sizeof(num));
    memset(flag,0,sizeof(flag));
    LCS();
    printf("%d\n",num[strlen(a)][strlen(b)]);
    getLCS();
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,dp[2][10086],t;
    char a[10086],b[10086];
    bool now,pre;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s%s",a,b);
        memset(dp,0,sizeof(dp));
        int lena=strlen(a),lenb=strlen(b);
        for(now=1,pre=0,i=0; i<lena; i++)
            for(swap(now,pre),j=0; j<lenb; j++)
                if(a[i]==b[j])
                    dp[now][j+1]=dp[pre][j]+1;
                else
                    dp[now][j+1]=dp[pre][j+1]>dp[now][j]?dp[pre][j+1]:dp[now][j];
        printf("%d\n",dp[now][lenb]);
    }
    return 0;
}
 */