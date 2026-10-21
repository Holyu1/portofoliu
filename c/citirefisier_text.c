#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void citire(FILE *f, int a[][10], int *n, int *m) {
    fscanf(f,"%d",&*n);
    fscanf(f,"%d",&*m);
    for (int i = 1;i<=*n;i++)
        for (int j = 1;j<=*n;j++)
            a[i][j]=0;
    for (int i = 0;i<=*m;i++) {
        int x,y;
        fscanf(f,"%d %d",&x,&y);
        a[x][y]=a[y][x]=1;
    }
}
int main() {
    int a[10][10],n,m;
    FILE *f=fopen("text.txt","r");
    citire(f,a,&n,&m);
    fclose(f);
    for (int i = 1;i<=n;i++) {
        for (int j = 1;j<=n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }
}