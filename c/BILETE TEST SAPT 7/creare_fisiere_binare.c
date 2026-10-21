#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct {
    char zi,luna;
    int an;
}DATA;
typedef struct {
    char ora,minut;
}orain;
typedef struct {
    char ora,minut;
}orasf;
typedef struct{
    char an,unde,npren[30];
    int nrmat,grupa;
    DATA data;
    orain orai;
    orasf oras;
}informatii;
void creares(char numef[]) { // secvential
    FILE *f = fopen(numef,"wb");
    informatii p;
    if (f==NULL) {
        printf("Erreur\n");
    }else {
        printf("nrmat: "); scanf("%d",&p.nrmat);
        while (!feof(stdin)) {
            getchar();
            printf("nume,prenume: "); scanf("%s",p.npren);
            printf("an student: "); scanf(" %c",&p.an);
            printf("grupa: "); scanf("%d",&p.grupa);
            printf("unde?: "); scanf(" %c",&p.unde);
            printf("cand?(zi):"); scanf(" %c",&p.data.zi);
            printf("cand?(luna):");scanf(" %c",&p.data.luna);
            printf("cand?(an)");scanf("%d",&p.data.an);
            printf("inceput?(min)");scanf(" %c",&p.orai.minut);
            printf("inceput?(ora)");scanf(" %c",&p.orai.ora);
            printf("sfarsit?(min)");scanf(" %c",&p.oras.minut);
            printf("sfarsit?(ora)");scanf(" %c",&p.oras.ora);
            fwrite(&p,sizeof(informatii),1,f);
            printf("nrmat: "); scanf("%d",&p.nrmat);
        }
        fclose(f);
    }
}
int main()
{
    char numef[30];
    printf("Nume fisier frt: ");
    scanf("%s", numef);
    creares(numef);

}
