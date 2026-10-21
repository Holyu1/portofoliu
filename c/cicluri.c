#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void ciclu(int k, int *k1, int a[][20], int m[], int v[], int n) {
    m[k]=1;
    (*k1)++;
    v[*k1]=k;
    for (int i = 1;i<=n;i++)
        if (a[i][k]==1 && m[i]==0)
            ciclu(i,k1,a,m,v,n);
}
int main() {
    int n,a[20][20],p,vf,m[20],v[20],k1=0;
    FILE *f=fopen("date1.txt","r");
    fscanf(f,"%d",&n);
    fscanf(f,"%d",&p);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            a[i][j]=0;
    for (int i= 1;i<=n;i++)
        m[i]=0;
    for (int i=1;i<=p;i++) {
        int x,y;
        fscanf(f,"%d %d",&x,&y);
        a[x][y]=a[y][x]=1;
    }
    fscanf(f,"%d",&vf);
    ciclu(vf,&k1,a,m,v,n);
    if (a[v[n]][v[1]]==1)
        for (int i = 1;i<=k1;i++)
            printf("%d ",v[i]);
}