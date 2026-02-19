#include <stdio.h>
#include <conio.h>
int main(){
    int i,j,k,m,n,aux;
    scanf("%d %d",&m,&n);
    k=0;
    int a[m][n],v[m*n];
    for(i=0;i<=m-1;i++)
        for(j=0;j<=n-1;j++)
            {
              scanf("%d",&a[i][j]);
              v[k]=a[i][j];
              k++;
            }
    for (i=0;i<=k-2;i++)
        for (j=i+1;j<=k-1;j++)
            if (v[i]>v[j]) {
                aux=v[i];
                v[i]=v[j];
                v[j]=aux;
            }
    k=0;
    for (i=0;i<=m-1;i++) {
        for (j=0;j<=n-1;j++) {
            a[i][j]=v[k];
            k++;
        }
    }
    for (i=0;i<=m-1;i++) {
        for (j=0;j<=n-1;j++) {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
