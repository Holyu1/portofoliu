#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int a[10][10],m[10];
void dfs(int k, int n, int m[])
{
    printf("%d ", k);
    m[k]=1; //vizitam varful curent x
    for(int i=1;i<=n;i++) // determinam vecinii nevizitati ai lui x
        if(a[k][i]==1 && m[i]==0)
            dfs(i,n,m);// continuam parcurgerea cu vecinul curent i
}
int main() {
    int n,p,x,y;
    scanf_s("%d %d",&n,&p);
    for (int i= 1;i<=p;i++) {
        scanf_s("%d %d",&x,&y);
        a[x][y]=a[y][x]=1;
    }
    int varf;
    scanf_s("%d",&varf);
    int ok = 1;
    dfs(varf,n,m); // non-generalizata
    //while (ok==1) { //generalizata
        //ok=0;
       // for (int i = 1; i<=n; i++)
       //     if (m[i] == 0) {
        //        ok=1;
        //        dfs(i,n,m);
        //    }
    //}
}
