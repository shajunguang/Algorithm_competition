#include <vector>
#include <iostream>
#include <typeinfo>
using namespace std;
int main(){
	vector<int> mv(5,0);
	cout<<"C++ style auto iterating"<<endl;
	for(auto it:mv)cout<<it<<" ";
	cout<<endl;
	
	cout<<"C style iterating"<<endl;
	for(int i=0;i<(int)mv.size();i++)
		cout<<mv[i]<<" ";
	cout<<endl;
	
	cout<<"used as a array"<<endl;
	for(int i=0;i<5;i++)
		mv[i]=i;
	for(auto it:mv)
		cout<<it<<" ";
	cout<<endl;
	
	cout<<"push back method "<<endl;
	for(int i=6;i<=10;i++)
		mv.push_back(i);
	for(auto it:mv)
		cout<<it<<" ";
	cout<<endl;
	mv.pop_back();
	for(auto it:mv)cout<<it<<" ";
	cout<<endl;
	
	cout<<"multidimension "<<endl;
	vector<vector<int>> mv2(5,vector<int>());
	mv2[0].push_back(1);
	mv2.push_back(vector<int> ());	//add a dimension
	
	
	vector<vector<int>> mv3(5);
	
	mv3[0].emplace_back(1);
	//cout<<typeid(mv3[0]).name()<<endl;
	return 0;
}