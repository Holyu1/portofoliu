#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int sol(int k, int x[], int a[][20]) {
    if (k<=1)
        return 0;
    if (a[x[0]][x[k]]==0)
        return 0;
    return 1;
}
int ok(int k, int x[], int a[][20]) {
    if (k>1)
        if (a[x[k-1]][x[k]]==0)
            return 0;
    for (int i = 0;i<=k-1;i++)
        if (x[k]==x[i])
            return 0;
    return 1;
}
void back(int k, int n, int a[][20], int x[]) {
    for (int i = 1;i<=n;i++) {
        x[k]=i;
        if (ok(k,x,a)==1)
            if (sol(k,x,a)==1) {
                for (int j = 0; j<=k;j++)
                    printf("%d",x[j]);
                printf("%d",x[0]);
                printf("\n");
            }else {
                back(k+1,n,a,x);
            }
    }
}
int main() {
    int n,a[20][20],p,x[20];
    FILE *f=fopen("date1.txt","r");
    fscanf(f,"%d",&n);
    fscanf(f,"%d",&p);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            a[i][j]=0;
    for (int i=0;i<=n-1;i++) {
        x[i]=0;
    }
    for (int i=1;i<=p;i++) {
        int x,y;
        fscanf(f,"%d %d",&x,&y);
        a[x][y]=a[y][x]=1;
    }
    back(0,n,a,x);
}