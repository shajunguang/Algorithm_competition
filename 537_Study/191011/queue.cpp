#include <queue>
#include <iostream>
using namespace std;
int main(){
	queue<int> q;	//FIFO(first in first out)
	for(int i=0;i<10;i++)q.push(i);
	while(!q.empty())
	{
		int no=q.front();q.pop();
		cout<<no<<endl;
	}
	return 0;
}