#include <bits/stdc++.h>
using namespace std;

int main(){
	pair<char,char> gra1[6][6];
	pair<char,char> gra2[6][6];
	for(int i=0;i<6;i++)
		for(int j=0;j<6;j++)gra2[i][j]=make_pair('n','n');
	int rule[7][4]={{0,0,0,0},{2,3,4,5},{1,4,6,3},\
		{1,2,5,6},
		{1,2,5,6} ,  
		{1,4,6,3},
		{2,4,3,5}
		};
	
	string str;
	while(cin>>str)
	{
		for(int i=0;i<6;i++)
			for(int j=0;j<4;j++){
				int u=i+1;
				int nx=rule[i+1][j];
				gra1[u-1][nx-1] =make_pair(str[u-1] ,str[nx-1]);
			}
		for(int i=0;i<6;i++)
			for(int j=0;j<4;j++){
				int u=i+1;
				int nx=rule[i+1][j];
				gra2[u-1][nx-1] =make_pair(str[6+u-1] ,str[6+nx-1]);
			}
		vector<int> per;
		for(int i=0;i<=5;i++)per.push_back(i);
		int finsuc=0;
		do{
			int suc=1;
			for(int i=0;i<6;i++){
				for(int j=0;j<4;j++){
					int u=i+1;
					int nx=rule[i+1][j];
					int mapu=per[u-1];
					int mapnx=per[nx-1];
					char c1=gra1[u-1][nx-1].first;
					char c2=gra1[u-1][nx-1].second;
					char mapc1=gra2[mapu][mapnx].first;
					char mapc2=gra2[mapu][mapnx].second;
					if(mapc1 != c1 || mapc2 != c2){
						suc=0;
					}
				}
				
			}
			if(suc){
				finsuc=1;
				cout<<"TRUE"<<endl;
				break;
			}
		}while(next_permutation(per.begin(),per.end()));
		if(!finsuc)cout<<"FALSE"<<endl;
	}
	
}