#define _CRT_SECURE_NO_WARNINGS
#include <limits.h>
#include <stdio.h>
void parc(int i, int prev[]) {
    if (i==0)
        printf("%d ",i);
    else {
        printf("%d ",i);
        parc(prev[i],prev);
    }
}
int main() {
    int n,m,i,j,k=0,nc,min;
    printf("nr noduri:");
    scanf_s("%d",&n);
    int k1=n-1;
    int a[n][n],vis[n],unvis[k1],prev[n],shdis[n];
    printf("nr muchii:");
    scanf_s("%d",&m);
    printf("nod start:");
    scanf_s("%d",&nc);
    shdis[nc]=0;
    for (i=0;i<=n-1;i++)
        for (j=0;j<=n-1;j++)
            a[i][j]=a[j][i]=0;
    printf("muchii: \n");
    for (i=0;i<=m-1;i++) {
        int x,y,z;
        scanf_s("%d %d %d",&x,&y,&z);
        a[x][y]=a[y][x]=z;
    }
    for (i=0;i<=n-1;i++)
        prev[i]=-1;
    for (i=0;i<=k1-1;i++)
        unvis[i]=i;
    for (i=0;i<=n-1;i++)
        if (i!=nc)
            shdis[i]=INT_MAX;
    while (k1!=0) {
        min=INT_MAX;
        for (i=0;i<=n-1;i++) {
            int ok = 0;
            for (j=0;j<=k-1 && ok == 0;j++)
                if (vis[j]==i)
                    ok=1;
            if (ok==0)
                if (shdis[i]<min) {
                    min=shdis[i];
                    nc=i; // aleg nodul nevizitat cu distanta minima fata de nodul de start ca nodul curent
                }
        }
        for (i=0;i<=k1-2;i++)
            unvis[i]=unvis[i+1]; // il scot din nevizitate
        k1--;
        vis[k]=nc; // il bag in vizitate
        k++;
        for (i=0;i<=n-1;i++) {
            if (a[nc][i] != 0) {
                int ok = 0;
                for (j=0;j<=k-1;j++)
                    if (vis[j]==i)
                        ok=1;
                if (ok==0)
                    if (shdis[i]>shdis[nc]+a[nc][i]) {
                        shdis[i]=shdis[nc]+a[nc][i]; // actualizez distantele de la nodul de  start la vecinii nevzitati ai nodului curent
                        prev[i]=nc;
                    }
            }
        }
    }
    printf("Distantele minime: ");
    for (i=0;i<=n-1;i++)
        printf("%d ",shdis[i]);
    printf("\n");
    printf("vector noduri anterioare: ");
    for (i=0;i<=n-1;i++)
        printf("%d ",prev[i]);
    printf("\n");
    parc(3,prev);
}