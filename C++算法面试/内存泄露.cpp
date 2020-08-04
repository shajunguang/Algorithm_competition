#ifdef VCZH_CHECK_MEMORY_LEAKS
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#define VCZH_CHECK_MEMORY_LEAKS_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new VCZH_CHECK_MEMORY_LEAKS_NEW
#endif
#include<bits/stdc++.h>

int a[102];
int fun1(int i) {
    if(a[i]) return a[i];
    return i <= 1 ? 1 : fun1(i - 1) + fun1(i - 3);
}

int fun2(unsigned int i) {
    return ((i >> 8) & 0x64) & (((i << 8) & 0x9346) >> 8);
}

int main() {
    a[0]=a[1]=1;a[2]=2;
    for(int i=3;i<=101;i++) a[i]=a[i-1]+a[i-3];
    int n = fun2(a[101]) % 4;
    printf("%d", n);
    return 0;
}