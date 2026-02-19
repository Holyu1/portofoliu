
#include <stdio.h>
#include <conio.h>
int main(){
    int i,j,n, sumadp=0,sumac=0,sumal=0,sumads=0;
    scanf("%d",&n);
    int a[n][n];
    for (i=0;i<n;i++) {
        for (j=0;j<n;j++) {
            scanf("%d",&a[i][j]);
        }
    }
    for (i=0;i<n;i++) {
        sumac=sumac+a[i][0];
    }
    for (j=0;j<n;j++) {
        sumal=sumal+a[0][j];
    }
    for (i=0;i<n;i++) {
        for (j=0;j<n;j++) {
            if (i==j)
                sumadp=sumadp+a[i][j];
            if (i+j==n-1)
                sumads=sumads+a[i][j];
        }
    }
    if (sumal == sumac && sumal == sumadp && sumadp == sumads)
        printf("DA");
    else
        printf("NU");
}
