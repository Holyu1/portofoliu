#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define INFINIT 1000000000
int main() {
    int n,muc,f[10],d[10],w[10][10],i,j,k,start,dest;
    FILE *p = fopen("graf.txt","r");
    fscanf(p,"%d",&n);
    fscanf(p,"%d",&muc);
    for (i=1;i<=n;i++){
        for (int j=1;j<=n;j++) {
            w[i][j]=INFINIT;
        }
    }
    for (i=0;i<=muc-1;i++) {
        int x,y,z;
        fscanf(p,"%d %d %d ",&x,&y,&z);
        w[x][y]=w[y][x]=z;
    }
    fscanf(p,"%d",&start);
    fscanf(p,"%d",&dest);
    for (k=1;k<=n;k++)
        for (j=1;j<=n;j++)
            for (i=1;i<=n;i++)
                if (w[i][k]!=INFINIT && w[k][j]!=INFINIT && w[i][j]>w[i][k]+w[k][j])
                    w[i][j]=w[i][k]+w[k][j];

}