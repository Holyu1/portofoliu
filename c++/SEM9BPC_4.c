
#include <stdio.h>
#include <conio.h>
int main(){
    int i,j,n,p;
    scanf("%d %d",&n, &p);
    int a[n][p],x[n],y[p];
    for (i=0;i<n;i++) {
        for (j=0;j<p;j++) {
            scanf("%d",&a[i][j]);
        }
    }
    for (i=0;i<n;i++) {
        scanf("%d",&x[i]);
    }
    for (j=0;j<p;j++) {
        for (i=0;i<n;i++) {
            y[j]=y[j]+x[i]*a[i][j];
        }
    }
    for (i=0;i<p;i++)
        printf("%d ",y[i]);
}
