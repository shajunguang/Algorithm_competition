#include<bits/stdc++.h>
using namespace std;
int r[51],p[51];

int main()
{
    int N;
    cin>>N;
    for(int i=0;i<N;i++) cin>>r[i];
    for(int i=0;i<N;i++) cin>>p[i];
    for(int i=2;i<=2*N;i++) {
        int f=1,sum=0,t=i;
        for (int j = 0; j < N; j++) {
            if (t >= p[j])  t -= p[j];
            else if(r[j] >= sum) {f=0;break;}
            sum += r[j];
        }
        if(f) {cout<<i<<endl;break;}
    }
    return 0;
}