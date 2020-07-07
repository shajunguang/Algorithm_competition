#include <set>
#include <iostream>
using namespace std;
struct comp{
	
	bool operator()(const int &a,const int &b)const{
		return a<b;
	}
};
int main(){
	set<int> ms;	//element can not be repeated
	//useful while we need to iterate then throw away repeated elements
	ms.insert(1);
	ms.insert(1);
	for(auto it:ms)cout<<it<<endl;
	set<int,comp> ms2;	//equal to set<int,less<int>> ms2;
	ms2.insert(1);
	ms2.insert(2);
	for(auto it:ms2)cout<<it<<" ";
	cout<<endl;
	return 0;
}