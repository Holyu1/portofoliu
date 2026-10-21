#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int x[10];
int ok(int k) {
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
void back(int n, int k) {
    for (int i = 0;i<=n-1;i++) {
        x[k]=i;
        if (ok(k)==1)
            if (sol(k,n)==1) {
                for (int j=0;j<=n-1;j++)
                    printf("%d",x[j]);
                printf("\n");
            }
            else {
                back(n,k+1);
            }
    }
}

int main() {
    int n;
    scanf("%d",&n);
    back(n,0);
}
