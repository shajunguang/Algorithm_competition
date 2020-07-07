#include <bits/stdc++.h>
using namespace std;
const int MAXN=10;
int chess[MAXN][MAXN];
int opflag;
int initr,initc;
int dr[8]={-1,-1,-1,0,1,1,1,0};
int dc[8]={1,0,-1,-1,-1,0,1,1};
int chgcolor;
int dfs_check(int r,int c,int type,int cur){
	//cerr<<r<<" "<<c<<" "<<type<<" "<<chess[r][c]<<" "<<cur<<endl;
	if(r<0 || c<0||r>=8||c>=8)return 0;
	if(chess[r][c]==2 && (r!=initr || c!=initc))return 0;
	if(chess[r][c]==(!cur))opflag=1;
	if(chess[r][c]==cur && (r!=initr || c!=initc)){
		
		if(opflag)return 1;
		else return 0;
	}
	int nr=r+dr[type];
	int nc=c+dc[type];
	int ret= dfs_check(nr,nc,type,cur);
	if(ret && chgcolor && chess[r][c]==(!cur))
		chess[r][c]=cur;
	return ret;
}
set<pair<int,int>> leg;
void checklegal(int cur){
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++){
			if(chess[i][j]==2){
				for(int z=0;z<8;z++){
					opflag=0;
					initr=i;initc=j;
					chgcolor=0;
					int ret=dfs_check(i,j,z,cur);
					
					if(ret){
						leg.insert({i,j});
					}
				}
			}

	}
}
int main(){
	int cas;cin>>cas;
	for(int ca=0;ca<cas;ca++){
		for(int i=0;i<8;i++)
			for(int j=0;j<8;j++)
			{
				char c;cin>>c;
				if(c=='W')chess[i][j]=0;
				else if (c=='B')chess[i][j]=1;
				else chess[i][j]=2;
			}
		
		char c;cin>>c;
		int cur;
		c=='W'?cur=0:cur=1;
		string str;
		while(cin>>str && str[0]!='Q'){
			if(str.size()==1){
				
				leg=set<pair<int,int>> ();
				checklegal(cur);
				int cc=0;
				if(!leg.size())printf("No legal move.");
				else for(auto it:leg){
					if(cc)printf(" ");
					printf("(%d,%d)",it.first+1,it.second+1);
					cc++;
				}
				printf("\n");
			}else{
				int mr,mc;
				mr=str[1]-'0';
				mc=str[2]-'0';
				mr-=1;
				mc-=1;
				leg=set<pair<int,int>> ();
				checklegal(cur);
				if(leg.size()!=0)
				for(int z=0;z<8;z++){
					opflag=0;
					initr=mr;initc=mc;
					chgcolor=1;
					dfs_check(mr,mc,z,cur);
				}
				else{
					
					cur=!cur;
					for(int z=0;z<8;z++){
						opflag=0;
						initr=mr;initc=mc;
						chgcolor=1;
						dfs_check(mr,mc,z,cur);
					}
				}
				chess[mr][mc]=cur;
				int bl,wh;
				bl=wh=0;
				for(int i=0;i<8;i++)
					for(int j=0;j<8;j++)
						if(chess[i][j]==1)bl++;
						else if(chess[i][j]==0)wh++;
				printf("Black -%3d White -%3d\n",bl,wh);
				cur=!cur;
			}
		}
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				if(chess[i][j]==1)printf("B");
				else if(chess[i][j]==0)printf("W");
				else printf("-");
			}
			printf("\n");
		}
		if(ca!=cas-1)printf("\n");
	}
	return 0;
}