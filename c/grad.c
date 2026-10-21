#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int gradneo(int v, int a[][10], int n) { // neorientat
    int suma=0;
    for (int j = 0;j<=n-1;j++)
        suma=suma+a[v][j];
    return suma;
}
int grado(int v, int a[][10], int n) { // orientat
    int suma=0;
    for (int j = 0;j<=n-1;j++)
        suma=suma+a[v][j];
    for (int i = 0;i<=n-1;i++)
        suma=suma+a[i][v];
    return suma;
}
int main() {
    int n,m,i,j,vf;
    printf("nr noduri:"); scanf_s("%d",&n);
    printf("nr muchii:"); scanf_s("%d",&m);
    int a[10][10];
    for (i=0;i<=n-1;i++)
        for (j=0;j<=n-1;j++)
            a[i][j]=0;
    printf("muchii:\n");
    for (i=0;i<=m-1;i++) {
        int x,y;
        scanf_s("%d %d",&x,&y);
        a[x-1][y-1]=a[y-1][x-1]=1; // la orientat am doar a[x][y]=1
    }
    printf("varf:"); scanf_s("%d",&vf);
    printf("gradul nodului %d este %d",vf,gradneo(vf-1,a,n));
}