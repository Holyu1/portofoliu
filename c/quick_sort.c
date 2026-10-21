#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void quick_sort(int st, int dr, int v[]) {
    if (st<dr) {
        int aux,m=(st+dr)/2;
        aux=v[st];
        v[st]=v[m];
        v[m]=aux;
        int i=st,j=dr;
        while (i<j)

    }
}
int main() {
    int n,i;
    printf("n="); scanf("%d",&n);
    int v[n];
    printf("elemente vector:\n");
    for (i=0;i<n;i++)
        scanf("%d",&v[i]);
    quicksort
}
