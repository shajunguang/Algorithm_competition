#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> staconst;
const int MAXN=15;
int sta[MAXN];
int main(){
	int n;
	int cas=0;
	while(cin>>n && n){
		cas++;
		staconst=vector<pair<int,int>> ();
		
		for(int i=0;i<n;i++){
			int a,b,c;cin>>a>>b>>c;
			staconst.push_back(make_pair(a,b));
			sta[i]=c-1;
		}
	int suc=0;
	for(int time=1;time<=(int)1e6;time++){
		int awake=0;
		set<int> judge;
		for(int men=0;men<n;men++){
			if(sta[men]<staconst[men].first)awake++;
			if(sta[men]==staconst[men].first-1){
				judge.insert(men);
			}else sta[men]=(sta[men]+1)%(staconst[men].first+staconst[men].second);
		}
		if(awake==n){
			suc=1;
			printf("Case %d: %d\n",cas,time);
			break;
		}
		for(auto it:judge){
			if(awake>=(n-awake))sta[it]=0;
			else sta[it]++;
		}
	}
	if(!suc)printf("Case %d: %d\n",cas,-1);
	
	}
	return 0;
}