#include<bits/stdc++.h>
using namespace std;
int m[10][10];

int main()
{
    int N,M;
    cin>>N;
    for(int i=0;i<N;i++)for(int j=0;j<N;j++)cin>>m[i][j];
    cin>>M;
    int n=M%4;
    switch(n){
        case 0:
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++)cout<<m[i][j];
                cout<<endl;
            }
            break;
        case 1:
            for(int j=0;j<N;j++){
                for(int i=N-1;i>=0;i--) cout<<m[i][j]<<" ";
                cout<<endl;
            }
            break;
        case 2:
            for(int i=N-1;i>=0;i--){
                for(int j=N-1;j>=0;j--) cout<<m[i][j]<<" ";
                cout<<endl;
            }
            break;
        case 3:
            for(int j=N-1;j>=0;j--){
                for(int i=0;i<N;i++)cout<<m[i][j]<<" ";
                cout<<endl;
            }
            break;
    }
    return 0;
}