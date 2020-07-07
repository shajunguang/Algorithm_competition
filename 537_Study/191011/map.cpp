#include <map>
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;
map<string,int> mm;
vector<string> sto;
//return the index of sto
//while dealing with a lot of string , this function is useful

int string2int(string in){
	if(mm.count(in))return mm[in];
	else{
		sto.push_back(in);
		return  mm[in]=sto.size()-1;
	}
}
struct comp{
	bool operator()(const string &a,const string &in)const{
		return a[0]>=in[0];
	}
};
typedef struct mytype{
	int a,b,c;
};
int main(){
	string str;
	str="test 1";
	int no=string2int(str);
	cout<<no<<endl;
	cout<<sto[no]<<endl;
	str="test 2 ";
	no=string2int(str);
	cout<<no<<endl;
	cout<<sto[no]<<endl;
	cout<<"C++ style"<<endl;
	for(auto it:mm){
		cout<<it.first<<" "<<it.second<<endl;
	}
	cout<<"C style"<<endl;
	for(auto it=mm.begin();it!=mm.end();it++){
		cout<<it->first<<" "<<it->second<<endl;
	}
	cout<<"Customize overloading "<<endl;
	map<string,int,comp> mm2;
	str="abc";
	mm2[str]=1;
	str="bcd";
	mm2[str]=2;
	for(auto it:mm2){
		cout<<it.first<<endl;
	}
	cout<<"default overloading "<<endl;
	map<string,int,less<string>> mm3;
	str="abc";
	mm3[str]=1;
	str="bcd";
	mm3[str]=2;
	for(auto it:mm3){
		cout<<it.first<<endl;
	}
	unordered_map<string,int> morm;	//hash 查找
	
	return 0;
}