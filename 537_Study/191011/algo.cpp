#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main(){
	int a[]={5,3,4,1,10};
	sort(a,a+(sizeof(a)/sizeof(a[0])));
	cout<<"sort default sorting"<<endl;
	for(int i=0;i<sizeof(a)/sizeof(a[0]);i++)
		cout<<a[i]<<endl;
	vector<int> mv;
	for(int i=0;i<(sizeof(a)/sizeof(a[0]));i++)
		mv.push_back(a[i]);
	cout<<"sort sorting overload"<<endl;
	sort(mv.begin(),mv.end(),greater<int>());	//注意 这里用greater刚好和优先队列里面重载了相反方向
	for(auto it:mv)
		cout<<it<<endl;
	cout<<"lower bound"<<endl;
	
	sort(mv.begin(),mv.end(),less<int>());	//注意这里 必须重新从小到大排序才能使用lower_bound
	cout<<"original "<<endl;
	for(auto it:mv)
		cout<<it<<" ";
	cout<<endl;
	int pos=lower_bound(mv.begin(),mv.end(),5)-mv.begin();
	if(pos!=mv.size()-1)
	cout<<pos<<" "<<mv[pos]<<endl;
	
	int pos2=upper_bound(mv.begin(),mv.end(),5)-mv.begin();
	if(pos2!=mv.size()-1)
	cout<<pos2<<" "<<mv[pos2]<<endl;

	cout<<"gcd function "<<endl;
	cout<<"22 11"<<endl;
	cout<<__gcd(22,11)<<endl;
	
	cout<<"min max function 11 22"<<endl;
	cout<<"min cases:"<<min(11,22)<<endl;
	cout<<"max cases "<<max(11,22)<<endl;
	
	
	mv.pop_back();
	mv.pop_back();
	cout<<"original"<<endl;
	for(auto it:mv)
		cout<<it<<" ";
	cout<<"next permutation"<<endl;
	cout<<endl;
	do{
		for(auto it:mv)
			cout<<it<<" ";
		cout<<endl;
	}while(next_permutation(mv.begin(),mv.end()));
	
	return 0;
}