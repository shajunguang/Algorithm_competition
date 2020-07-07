//用do{}while(0)来解决直接替换后的分号问题
#include <stdio.h>

#define PRINT1(a,b)        \
    {                  \
      printf("print a\n"); \
      printf("print b\n"); \
    }

#define      PRINT2(a, b)      \
  do{               \
      printf("print a\n"); \
      printf("print b\n"); \
    }while(0)

#define PRINT(a) \
    do{\
    printf("%s: %d\n",#a,a);\
    printf("%d: %d\n",a,a);\
    }while(0)

#define TYPE1(type,name)   type name_##type##_type  //双#号替代空格，输出链接
#define TYPE2(type,name)   type name##_##type##_type

#define ERROR_LOG(module)   fprintf(stderr,"error: "#module"\n") //单#号字符串化

int main()
{
    int a = 20;
    int b = 19;
    TYPE1(int, c);
    ERROR_LOG("add");
    name_int_type = a;
    TYPE2(int, d);
    d_int_type = a;

    PRINT(a);
    if (a > b)
    {
        PRINT1(a, b);
    }
    else
    {
        PRINT2(a, b);
    }
    return 0;
}