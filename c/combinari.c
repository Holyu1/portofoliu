#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int x[10];
int ok(int k) {
    for (int i = 0;i<=k-1;i++)
        if (x[i]>=x[k])
            return 0;
    return 1;
}
int sol(int k,  int p) {
    if (k==p-1)
        return 1;
    return 0;
}
void back(int n, int k, int p) {
    for (int i = 0;i<=n-1;i++) {
        x[k]=i;
        if (ok(k)==1)
            if (sol(k,p)==1) {
                for (int j=0;j<=p-1;j++)
                    printf("%d",x[j]);
                printf("\n");
            }
            else {
                back(n,k+1,p);
            }
    }
}
int main() {
    int n,p;
    scanf("%d %d",&n,&p);
    back(n,0,p);
}
