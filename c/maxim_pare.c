#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
void divide_et_impera(int st, int dr,int *max) {
    if (st==dr) {
        if (st%2==0)
            
    }else {
        int m = (st+dr)/2;
        divide_et_impera(st,m,max);
        divide_et_impera(m+1,dr,max);
    }
}
int main() {
   int n,i;
   printf("n:"); scanf("%d",&n);
   int v[n];
   for (i = 0;i<n;i++)
      scanf("%d",&v[i]);
}
