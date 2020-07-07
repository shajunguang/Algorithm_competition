#include<bits/stdc++.h>
using namespace std;
struct Recording{
    int id;
    string filename;
    int errorline;
    int errorcount=0;
}record[200];
bool cmp(struct Recording &a,struct Recording &b){
    if(a.errorcount==b.errorcount) return a.id<b.id;
    return a.errorcount>b.errorcount;
}
int main()
{
    freopen("in.txt","r",stdin);
    string filepath;
    int errorline,k=0;
    map<pair<string,int>,int> hash;
    while(cin>>filepath>>errorline){
        //cout<<filepath<<endl;
        string temp;
        for(int i=filepath.size()-1;i>=0;i--) {
            if (filepath[i] != '\\') temp += filepath[i];
            else break;
        }
        reverse(temp.begin(),temp.end());
        //cout<<temp<<endl;
        if(hash.count({temp,errorline})!=0) record[hash[{temp,errorline}]].errorcount++;
        else{
            record[k].filename=temp;record[k].errorline=errorline;
            record[k].id=k;record[k].errorcount++;
            hash[{temp,errorline}]=k;
        }
        k++;
    }
    sort(record,record+k,cmp);
    for(int i=0;i<min(8,k);i++){
        string temp=record[i].filename;
        temp=temp.size()>16?temp.substr(temp.size()-16,16):temp;
        cout<<temp<<" "<<record[i].errorline<<" "<<record[i].errorcount<<endl;
    }
    return 0;
}