#include<stdlib.h>
#include<iostream>
#define LOOP 10000
using namespace std;

int main()
{
    int rgnC=0;
    srand((int)time(0));
    for(int i=0;i<LOOP;i++){
        int x=rand();
        int y=rand();
        if(x*x+y*y<RAND_MAX*RAND_MAX) rgnC++;
    }
    cout<<rgnC<<endl;
    return 0;
}