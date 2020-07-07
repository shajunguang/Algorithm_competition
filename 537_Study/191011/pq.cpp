#include <queue>
#include <iostream>
using namespace std;
int main(){
	priority_queue<int,vector<int>> pq;
	int a[]={1,4,5,0,8,3,2};
	for(int i=0;i<sizeof(a)/sizeof(a[0]);i++){
		pq.push(a[i]);
	}
	cout<<"default sorting"<<endl;
	while(!pq.empty()){
		int no=pq.top();pq.pop();
		cout<<no<<endl;
	}
	priority_queue<int,vector<int>,greater<int> > pq2;
	
	for(int i=0;i<sizeof(a)/sizeof(a[0]);i++){
		pq2.push(a[i]);
	}
	cout<<"overload sorting"<<endl;
	while(!pq2.empty()){
		int no=pq2.top();pq2.pop();
		cout<<no<<endl;
	}
	return 0;
}