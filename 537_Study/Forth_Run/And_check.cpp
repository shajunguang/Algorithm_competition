//#include <bits/stdc++.h>
//using namespace std;
//class disJointUnionSet{
//	private:
//		vector<int> p;	//重点维护的变量 表示指向哪个作为父亲
//		vector<int> rank;	//重点维护的变量 表示树的高度
//		vector<int> setsize;
//		int numofset;
//
//	public:
//	disJointUnionSet(int n){
//		p.assign(n,0);
//		rank.assign(n,1);
//		setsize.assign(n,1);
//		for(int i=0;i<n;i++)p[i]=i;
//		numofset=n;
//	}
//	int find_set(int i){
//		return i==p[i]?i:p[i]=find_set(p[i]);
//	}
//	bool is_same_set(int i,int j){
//		return find_set(i)==find_set(j);
//	}
//	void UnionSet(int i,int j){
//		if(!is_same_set(i,j)){
//			numofset--;
//			int x=find_set(i);int y=find_set(j);
//			if(rank[x]<rank[y]){
//				p[x]=y;
//				setsize[y]+=setsize[x];
//			}else{
//				p[y]=x;
//				setsize[x]+=setsize[y];
//				if(rank[x]==rank[y])rank[x]++;
//			}
//		}
//	}
//	int setSize(int i){
//		return setsize[find_set(i)];
//	}
//	int numOfSet(void){
//		return numofset;
//	}
//};
//int main(){
//	disJointUnionSet dis(5);
//	cout<<"before union number of set"<<endl;
//	cout<<dis.numOfSet()<<endl;
//	cout<<"0 & 1 Is same set?"<<endl;
//	cout<<dis.is_same_set(0,1)<<endl;
//	dis.UnionSet(0,1);
//	cout<<"Union 0 and 1 number of set"<<endl;
//	cout<<dis.numOfSet()<<endl;
//	cout<<"0 & 1 Is same set?"<<endl;
//	cout<<dis.is_same_set(0,1)<<endl;
//	return 0;
//}