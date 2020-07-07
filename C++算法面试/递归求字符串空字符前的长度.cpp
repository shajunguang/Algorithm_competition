#include<iostream>
using namespace std;

int mystrlen(char*  buf,int N){
    if(buf[0]==0 || N==0) return 0;
    if(N==1) return 1;
    int t=mystrlen(buf,N/2);
    if(t<N/2) return t;
    return t+mystrlen(buf+N/2,(N+1)/2);
}
int main()
{
    char buf[]={'a','b','c','d','e','f','\0','x','y','z'};
    int k;
    k=mystrlen(buf, 20);
    cout<<k<<endl;
    return 0;
}