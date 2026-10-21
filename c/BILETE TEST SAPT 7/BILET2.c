#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
typedef struct {
    char zi,luna;
    int an;
}DATA;
typedef struct {
    char ora,minut;
}ora;
typedef struct{
    char an,unde,npren[30];
    int nrmat,grupa;
    DATA data;
    ora orai;
    ora oras;
}informatii;
void rezolvare(char numef[]) {
    FILE *f = fopen(numef,"rb");
    FILE *f1 = fopen("sss.dat","wb");
    informatii p;
    if (f == NULL || f1 == NULL) {
        printf("eroare");
    }else {
        int nrm;
        printf("nrmat elev steregere: "); scanf("%d",&nrm);
        fread(&p, sizeof(informatii), 1, f);
        while (!feof(f)) {
            if (p.nrmat != nrm)
                fwrite(&p, sizeof(informatii), 1, f1);
            fread(&p, sizeof(informatii), 1, f);
        }
        fclose(f);
        fclose(f1);
        remove(numef);
        rename("sss.dat",numef);
    }
}

int main(){
    char numef[30];
    printf("nume fisier: "); scanf("%s",numef);
    rezolvare(numef);
}