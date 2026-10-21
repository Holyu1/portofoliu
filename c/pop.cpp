#include <stdio.h>
#include <string.h>
int main()
{
    int n,m;
    scanf("%d",&n);
    char s[n+1][100];
    char t[100]="";
    for (int i=1;i<=n;i++)
        scanf("%s",s[i]);
    scanf("%d",&m);
    int v[m];
    for (int i=0;i<m;i++)
        scanf("%d",&v[i]);
    for (int i=0;i<m;i++) {
        strcat(t,s[v[i]]);
        strcat(t," ");
    }
    printf("%s",t);
}

