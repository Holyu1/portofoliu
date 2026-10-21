#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int aranj(int n, int k) {
    if (k==0)
        return 1;
    return n*aranj(n-1,k-1);
}
int main() {
    int n,k;
    scanf("%d %d",&n,&k);
    printf("%d",aranj(n,k));
}