#include<bits/stdc++.h>
using namespace std;
char out[100][10000];

int main()
{
    //freopen("out.txt","w",stdout);
    int k;
    string s;
    cin>>k>>s;
    int c=0; //当前列
    memset(out,0,sizeof out);
    for(int _=0;_<s.size();_++){
        if(_) {for(int i=0;i<2*k+3;i++) out[i][c]=' '; c++;}
        switch(s[_]-'0'){
            case 0:
                out[0][c]=' ';for(int i=1;i<=k;i++)out[0][c+i]='-';out[0][c+k+1]=' ';
                for(int i=1;i<2*k+2;i++)
                {if(i==k+1){for(int _i=0;_i<=k+1;_i++)out[i][c+_i]=' ';continue;}
                    out[i][c]='|';for(int l=1;l<=k;l++)out[i][c+l]=' ';out[i][c+k+1]='|';}
                out[2*k+2][c]=' ';for(int i=1;i<=k;i++)out[2*k+2][c+i]='-';out[2*k+2][c+k+1]=' ';
                c+=k+2;
                break;
            case 1:
                out[0][c]=' ';for(int i=1;i<2*k+2;i++)
                {if(i==k+1){out[i][c]=' ';continue;}out[i][c]='|';}
                out[2*k+2][c]=' ';
                c++;
                break;
            case 2:
                out[0][c]=' ';for(int i=1;i<=k;i++)out[0][c+i]='-';out[0][c+k+1]=' ';
                for(int i=1;i<2*k+2;i++)
                {if(i==k+1){out[i][c]=' ';for(int _i=1;_i<=k;_i++)out[i][c+_i]='-';out[i][c+k+1]=' ';continue;}
                if(i<=k)out[i][c]=' ',out[i][c+k+1]='|';else out[i][c]='|',out[i][c+k+1]=' ';for(int l=1;l<=k;l++)out[i][c+l]=' ';}
                out[2*k+2][c]=' ';for(int i=1;i<=k;i++)out[2*k+2][c+i]='-';out[2*k+2][c+k+1]=' ';
                c+=k+2;
                break;
            case 3:
                out[0][c]=' ';for(int i=1;i<=k;i++)out[0][c+i]='-';out[0][c+k+1]=' ';
                for(int i=1;i<2*k+2;i++)
                {if(i==k+1){out[i][c]=' ';for(int _i=1;_i<=k;_i++)out[i][c+_i]='-';out[i][c+k+1]=' ';continue;}
                 for(int l=0;l<=k;l++)out[i][c+l]=' ';out[i][c+k+1]='|';}
                out[2*k+2][c]=' ';for(int i=1;i<=k;i++)out[2*k+2][c+i]='-';out[2*k+2][c+k+1]=' ';
                c+=k+2;
                break;
            case 4:
                for(int i=0;i<=k+1;i++)out[0][c+i]=' ';
                for(int i=1;i<2*k+2;i++)
                {if(i==k+1){out[i][c]=' ';for(int _i=1;_i<=k;_i++)out[i][c+_i]='-';out[i][c+k+1]=' ';continue;}
                    if(i<=k)out[i][c]='|',out[i][c+k+1]='|';else out[i][c]=' ',out[i][c+k+1]='|';for(int l=1;l<=k;l++)out[i][c+l]=' ';}
                for(int i=0;i<=k+1;i++)out[2*k+2][c+i]=' ';
                c+=k+2;
                break;
            case 5:
                out[0][c]=' ';for(int i=1;i<=k;i++)out[0][c+i]='-';out[0][c+k+1]=' ';
                for(int i=1;i<2*k+2;i++)
                {if(i==k+1){out[i][c]=' ';for(int _i=1;_i<=k;_i++)out[i][c+_i]='-';out[i][c+k+1]=' ';continue;}
                    if(i<=k)out[i][c]='|',out[i][c+k+1]=' ';else out[i][c]=' ',out[i][c+k+1]='|';for(int l=1;l<=k;l++)out[i][c+l]=' ';}
                out[2*k+2][c]=' ';for(int i=1;i<=k;i++)out[2*k+2][c+i]='-';out[2*k+2][c+k+1]=' ';
                c+=k+2;
                break;
            case 6:
                out[0][c]=' ';for(int i=1;i<=k;i++)out[0][c+i]='-';out[0][c+k+1]=' ';
                for(int i=1;i<2*k+2;i++)
                {if(i==k+1){out[i][c]=' ';for(int _i=1;_i<=k;_i++)out[i][c+_i]='-';out[i][c+k+1]=' ';continue;}
                    if(i<=k)out[i][c]='|',out[i][c+k+1]=' ';else out[i][c]='|',out[i][c+k+1]='|';for(int l=1;l<=k;l++)out[i][c+l]=' ';}
                out[2*k+2][c]=' ';for(int i=1;i<=k;i++)out[2*k+2][c+i]='-';out[2*k+2][c+k+1]=' ';
                c+=k+2;
                break;
            case 7:
                out[0][c]=' ';for(int i=1;i<=k;i++)out[0][c+i]='-';out[0][c+k+1]=' ';
                for(int i=1;i<2*k+2;i++)
                {if(i==k+1){for(int _i=0;_i<=k+1;_i++)out[i][c+_i]=' ';continue;}
                out[i][c]=' ';out[i][c+k+1]='|';for(int l=1;l<=k;l++)out[i][c+l]=' ';}
                for(int i=0;i<=k+1;i++)out[2*k+2][c+i]=' ';
                c+=k+2;
                break;
            case 8:
                out[0][c]=' ';for(int i=1;i<=k;i++)out[0][c+i]='-';out[0][c+k+1]=' ';
                for(int i=1;i<2*k+2;i++)
                {if(i==k+1){out[i][c]=' ';for(int _i=1;_i<=k;_i++)out[i][c+_i]='-';out[i][c+k+1]=' ';continue;}
                 out[i][c]='|';out[i][c+k+1]='|';for(int l=1;l<=k;l++)out[i][c+l]=' ';}
                out[2*k+2][c]=' ';for(int i=1;i<=k;i++)out[2*k+2][c+i]='-';out[2*k+2][c+k+1]=' ';
                c+=k+2;
                break;
            case 9:
                out[0][c]=' ';for(int i=1;i<=k;i++)out[0][c+i]='-';out[0][c+k+1]=' ';
                for(int i=1;i<2*k+2;i++)
                {if(i==k+1){out[i][c]=' ';for(int _i=1;_i<=k;_i++)out[i][c+_i]='-';out[i][c+k+1]=' ';continue;}
                    if(i<=k)out[i][c]='|',out[i][c+k+1]='|';else out[i][c]=' ',out[i][c+k+1]='|';for(int l=1;l<=k;l++)out[i][c+l]=' ';}
                out[2*k+2][c]=' ';for(int i=1;i<=k;i++)out[2*k+2][c+i]='-';out[2*k+2][c+k+1]=' ';
                c+=k+2;
                break;
        }
    }
    for(int i=0;i<=2*k+2;i++)
        for(int j=0;j<10000;j++){
            if(!out[i][j]){cout<<endl;break;}
            cout<<out[i][j];
        }
    return 0;
}