#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int comb(int n, int k) {
    if (k==0)
        return 1;
    return comb(n-1,k)+comb(n-1,k-1);
}
int main() {
    int n,k;
    scanf_s("%d %d",&n,&k);
    printf("%d",comb(n,k));
}