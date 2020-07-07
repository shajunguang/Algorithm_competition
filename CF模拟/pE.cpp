#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    map<string,int> hash;
    for(int i=0;i<n;i++){
        string name;
        cin>>name;
        if(!hash[name]){
            cout<<"OK"<<endl;
            hash[name]++;
        }else
            cout<<name+to_string(hash[name]++)<<endl;
    }
    return 0;
}
