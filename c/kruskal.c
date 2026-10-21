#define _CRT_SECURE_NO_WARNINGS
#include <limits.h>
#include <stdio.h>
int main() {
    int n,m,i,j,S=0;
    printf("nr noduri:");
    scanf_s("%d",&n);
    printf("nr muchii:");
    scanf_s("%d",&m);
    int a[m][3],aux,t[n];
    printf("muchii:\n");
    for (i=0;i<=m-1;i++) {
        int x,y,z;
        scanf_s("%d %d %d",&x,&y,&z);
        a[i][0]=x;
        a[i][1]=y;
        a[i][2]=z;
    }
    for (i=0;i<=n-1;i++)
        t[i]=i;
    for (i=0;i<=n-2;i++)
        for (j=i+1;j<=n-1;j++)
            if (a[i][2] > a[j][2]) {
                aux=a[i][0];
                a[i][0]=a[j][0];
                a[j][0]=aux;
                aux=a[i][1];
                a[i][1]=a[j][1];
                a[j][1]=aux;
                aux=a[i][2];
                a[i][2]=a[j][2];
                a[j][2]=aux;
            }
    for (i=0;i<=m-1;i++) {
        if (t[a[i][0]]!= t[a[i][1]]) {
            S=S+a[i][2];
            for (j=0;j<=n-1;j++)
                if (t[j]==a[i][1])
                    t[j]=a[i][0];
        }
    }
    printf("%d",S);
}