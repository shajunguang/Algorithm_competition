#include<bits/stdc++.h>
using namespace std;

char *memmove(char *dest, const char *src, size_t n){
   char *p1=dest;
   const char *p2=src;

   if(p2<p1){ //src在dest后面有重叠，此时不能直接赋值，必须得倒序
       p2+=n;
       p1+=n;
       while(n--) *--p1=*--p2;
   }else{
       while(n--) *p1++=*p2++;
   }
   return p1;
}