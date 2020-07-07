//注意函数里实现细节，以及参数设置
#include<bits/stdc++.h>
using namespace std;
char* strcpy(char* strDest,const char* strSrc){
    assert((strDest!=NULL)&&(strSrc!=NULL));
    char* address=strDest;
    while((*strDest++=*strSrc++)!='\0');
    return address;
}
void GetMemory(char **p, int num){
    if(num<=0)
        printf("申请的内存空间要大于零!\n");
    *p = (char*)malloc(num);
    if(*p==NULL)
        printf("申请内存失败!\n");
}

void test(){
    char *str = NULL;
    GetMemory(&str, 100);
    strcpy(str, "hello world");
    printf("%s\n", str);
    free(str);
    str = NULL;
}
int main()
{
    char *s="1234";
    char *t=new char(10);
    cout<<strcpy(t,s)<<endl;
    delete(t);
    t=NULL;
    test();
}