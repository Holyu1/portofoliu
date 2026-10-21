#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int ok(int k, int x[]) {
    for (int i = 0;i<=k-1;i++)
        if (x[i]==x[k])
            return 0;
    return 1;
}
int sol(int k, int n) {
    if (k==n-1)
        return 1;
    return 0;
}
void back(int k, int x[], int n) {
    for (int i = 0;i<=n-1;i++) {
        x[k]=i;
        if (ok(k,x)==1)
            if (sol(k,n)==1) {
                for (int j=0;j<=n-1;j++)
                    printf("(%d,%d) ",x[j],j);
                printf("\n");
            }else
                back(k+1,x,n);
    }
}
int main() {
    int n;
    printf("dimensiune:\n"); scanf_s("%d",&n);
    int x[n];
    for (int i = 0;i<=n-1;i++)
        x[i]=0;
    back(0,x,n);
}