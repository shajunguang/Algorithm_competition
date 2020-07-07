#include"LinkQueue.h"

int main()
{
    char c;
    LinkQueue q;
    initQueue(&q);
    while((c=getchar()) && c!='#'){
        InsertQueue(&q,c);
    }
    ElemType e;
    while(!is_Empty(&q)){
        PopQueue(&q,&e);
        printf("%c ",e);
    }
    return 0;
}