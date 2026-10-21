#define _CRT_SECURE_NO_WARNINGS
#include <limits.h>
#include <stdio.h>
typedef struct {
    int x,y;
}ARCE;
int main() {
    int n,m,i,j,min,k=0,q;
    printf("nr noduri:");
    scanf_s("%d",&n);
    int vis[n],a[n][n];
    printf("nr muchii:");
    scanf_s("%d",&m);
    ARCE x[m];
    printf("muchii:\n");
    for (i=0;i<=n-1;i++)
        for (j=0;j<=n-1;j++)
            a[i][j]=0;
    for (i=0;i<=m-1;i++) {
        x[i].x=0;
        x[i].y=0;
    }
    for (i=0;i<=m-1;i++) {
        int x,y,z;
        scanf_s("%d %d %d",&x,&y,&z);
        a[x][y]=a[y][x]=z;
    }
    vis[k]=0;
    k++;
    printf("muchii parcurse: \n");
    while (k<=n-1) {
        min=INT_MAX;
        for (i=0;i<=k-1;i++) {
            for (j=0;j<=n-1;j++) {
                if (a[vis[i]][j]!=0) {
                    int ok = 1;
                    for (q=0;q<=k-1;q++) {
                        if (j==vis[q])
                            ok=0;
                    }
                    if (ok==1) {
                        if (a[vis[i]][j]<min) {
                            min=a[vis[i]][j];
                            vis[k]=j;
                            x[k].x=vis[i];
                            x[k].y=j;
                        }
                    }
                }
            }
        }
        k++;
    }
    for (i=1;i<=k-1;i++)
        printf("(%d,%d) ", x[i].x, x[i].y);
}