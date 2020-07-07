#include "LinearArray.h"

int main()
{
   sqlist L={{1,2,3,4,5},5};
   //cout<<L.length<<endl;
   if(!InsertList(&L, 4, 9)) cout<<"ERROR!";
   else ListPrint(&L);
   if(!ListDelete(&L, 1)) cout<<"ERROR!";
   else ListPrint(&L);
   return OK;
}