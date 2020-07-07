#include <bits/stdc++.h>
using namespace std;
const int MAXN=15;
int H[MAXN][MAXN];
int V[MAXN][MAXN];
int desr;int desc;
int initr;int initc;
int mcount;
void dfs(int r,int c,int sz){
	//cerr<<r<<" "<<c<<endl;
	if(r==desr && c==desc){
		mcount++;
		return ;
	}
	if(r == initr && c==initc){
		if(V[r][c]==1 )dfs(r+1,c,sz);
		if(H[r][c]==1 )dfs(r,c+1,sz);
	}else 
	if(c==initc+sz && V[r][c]==1 )dfs(r+1,c,sz);
	else if(r==initr+sz && H[r][c]==1)dfs(r,c+1,sz);
	else if(c==initc && V[r][c]==1 )dfs(r+1,c,sz);
	else if(r==initr && H[r][c]==1 )dfs(r,c+1,sz);
}
int main(){
	int n,m;
	int countc=0;
	while(cin>>n>>m){
		countc++;
		
		memset(H,0,sizeof(H));
		memset(V,0,sizeof(V));
		for(int ii=0;ii<m;ii++){
		char c;cin>>c;
		if(c=='H'){
			int i,j;cin>>i>>j;
			i-=1;
			j-=1;
			H[i][j] =1;
		}else {
			int i,j;cin>>i>>j;
			i-=1;j-=1;
			V[j][i]=1;
		}
		}
		int size[MAXN];
		for(int i=0;i<MAXN;i++)size[i]=0;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				for(int sz=1;sz<=n;sz++){
					if(i+sz>=n || j+sz>=n )break;
					 desr=i+sz; desc= j+sz;
					 mcount=0;
					initr = i;
					initc =j;
					dfs(i,j,sz);
					if(mcount==2)size[sz]++;
				}
			}
		if(countc>1){
			
			printf("**********************************\n");
			printf("\n");
		}
		printf("Problem #%d\n",countc);
		printf("\n");
		int suc=0;
		for(int i=0;i<MAXN;i++){
			if(size[i]){
				suc=1;
				printf("%d square (s) of size %d\n",size[i],i);
				}
			
		}
		if(suc==0)printf("No completed squares can be found.\n");
		printf("\n");
		
		
	}
	return 0;
}