#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int f(int st, int dr, int v[]) {
    if (st==dr)
        return v[st];
    int mijl=(st+dr)/2;
    return f(st,mijl,v)+f(mijl+1,dr,v);
}
int serie_taylor(int )
int main() {
    int v[5]={1,2,3,4,5};
    printf("%d",f(0,4,v));
}