#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void parc(int k, int vfiu[],int vfrt[]) { // un fel de dfs
    if (vfiu[k]!=0)
        parc(vfiu[k],vfiu,vfrt);
    printf("%d ",k);
    if (vfrt[k]!=0)
        parc(vfrt[k],vfiu,vfrt);
}
int main() {
    int n,R,vfiu[20],vfrt[20];
    FILE *f=fopen("date.txt","r");
    fscanf(f,"%d",&n);
    fscanf(f,"%d",&R);
    for (int i=1;i<=n;i++) {
        fscanf(f,"%d ",&vfiu[i]);
    }
    for (int i=1;i<=n;i++) {
        fscanf(f,"%d",&vfrt[i]);
    }
    parc(R,vfiu,vfrt);
    fclose(f);
}
