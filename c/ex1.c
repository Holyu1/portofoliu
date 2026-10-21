#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void rez(char numef[], int *k, int v[]) {
    FILE *f = fopen(numef, "r");
    if (f==NULL)
        printf("eroare vro");
    else {
        fscanf(f,"%d",&v[0]);
        (*k)++;
        while (!feof(f)) {
            fscanf(f,"%d",&v[*k]);
            (*k)++;
        }
        (*k)--;
    }
    fclose(f);
}
int main() {
    char numef[20];
    int v[30],k=0,i;
    printf("nume fisier: : "); scanf("%s",numef);
    rez(numef,&k,v);
    for (i=0;i<=k;i++) {
        printf("%d ",v[i]);
    }
}