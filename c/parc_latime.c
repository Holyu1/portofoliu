#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int n,i,j,x,y,k=0,vf;
    scanf_s("%d",&n);
    int a[n][n],m[n],v[n],t=0;
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            a[i][j]=0;
        }
    }
    for (i=0;i<n;i++)
        m[i]=0;
    while (!feof(stdin)) {
        scanf_s("%d %d",&x, &y);
        if (x==-1)
            break;
        a[x][y]=a[y][x]=1;
    }
    scanf_s("%d",&vf);
    v[k]=vf;
    k++;
    m[vf]=1;
    printf("%d ",vf);
    while (k!=0) {
        for (i=0;i<n;i++)
            if (a[i][v[0]]==1 && m[i]==0) {
                v[k]=i;
                k++;
                m[i]=1;
                printf("%d ",i);
            }
        for (i=0;i<=k-2;i++)
            v[i]=v[i+1];
        k--;
    } // pt non-generalizata e ok pana aici, pt generalizata de acum incolo
    int ok = 1;
    while (ok==1) {
        ok=0;
        for (i=0;i<n && ok == 0;i++)
            if (m[i]==0) {
                ok=1;
                v[k]=i;
                k++;
                m[i]=1;
                printf("%d ",i);
                while (k!=0) {
                    for (j=0;j<n;j++)
                        if (a[j][v[0]]==1 && m[j]==0) {
                            v[k]=j;
                            k++;
                            m[j]=1;
                            printf("%d ",j);
                        }
                    for (j=0;j<=k-2;j++)
                        v[j]=v[j+1];
                    k--;
                }
            }

    }
}
