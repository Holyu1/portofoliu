#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
int t[10],nr[10],x[10],aux[10],S1,S;
int ok(int k) {
    if (S1 > S) {
        return 0;
    }
    for (int i = 0; i<=k-1;i++) {
        if (x[i]>x[i+1]) {
            return 0;
        }
    }
    for (int i=0; i<=k;i++) {
        if (x[i]==t[i] && nr[i]==0) {
            return 0;
        }
    }
    return 1;
}
void back(int k,  int n) {
        for (int i = 0; i<=n-1;i++) {
            x[k]=t[i];
            S1=0;
            for (int j=0;j<=k;j++)
                S1=S1+x[j];
            if (ok(k)==1) {
                if (S==S1) {
                    for (int j = 0;j<=k;j++)
                        printf("%d ",x[j]);
                    printf("\n");
                    for (int j = 0; j<=n-1;j++)
                        nr[j]=aux[j];
                }else {
                    nr[i]--;
                    back(k+1,n);
                }
            }
        }
    }
int main() {
    int n,i;;
    printf("ce suma trebuie platita?:"); scanf_s("%d",&S);
    printf("cate tipuri de bancnote?:"); scanf_s("%d",&n);
    printf("ce bacnote ai si cate din fiecare? (de forma tip bancnota, nr din acel tip):\n");
    for (i=0;i<=n-1;i++) {
        scanf_s("%d %d",&t[i],&nr[i]);
    }
    for (i=0;i<=n-1;i++)
        aux[i]=nr[i];
    back(0,n);
}