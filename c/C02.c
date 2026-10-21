#include <stdio.h>
typedef struct
{
    int cant,cod;
    char nume[20],is;
    float pret;
}PRODUS;
void raport(char numef[]) {
    FILE *f=fopen(numef,"rb");
    PRODUS p;
    if(f==NULL) {
        printf("Error");
    }else {
        char numer[20];
        printf("numef raport: ");
        scanf("%s",numer);
        FILE *r=fopen(numer,"w");
        int max1=0,max2=0,max3=0,max4=0;
        if(r==NULL) {
            printf("Error");
        }else {
            fprintf(r,"Cod Cant Nume Pret\n");
            fread(&p,sizeof(p),1,f);
            while (!feof(f)) {
                fprintf(r,"%-3d %-4d %-4s %-.2f\n",p.cod,p.cant,p.nume,p.pret);
                fread(&p,sizeof(p),1,f);
            }
            fclose(r);
            fclose(f);
        }
    }
}
void consultare(char numef[]) {
    FILE *f=fopen(numef,"r");
    PRODUS p;
    if(f==NULL) {
        printf("Error\n");
    }else {
        int cod;
        printf("cod dorit = "); scanf("%d",&cod);
        while (!feof(stdin)) {
            fseek(f,0,0);
            int gasit = 0;
            fread(&p,sizeof(p),1,f);
            while (!feof(f) && gasit == 0) {
                if (p.cod==cod) {
                    printf("%s %d %4.2f \n",p.nume,p.cant,p.pret);
                    gasit=1;
                }else
                    fread(&p,sizeof(p),1,f);
            }
            if (gasit==0)
                printf("nu exista \n");
            printf("cod dorit = "); scanf("%d",&cod);
        }
        fclose(f);
    }
}
void adaugare(char numef[]) {
    FILE *f;
    f=fopen(numef,"rb+");
    PRODUS p;
    if (f == NULL) {
        printf("eroare");
    }else {
        fseek(f,0,2);
        printf("cod = ");
        scanf("%d",&p.cod);
        while (!feof(stdin)) {
            getchar();
            printf("cant = "); scanf("%d",&p.cant);
            printf("nume = "); scanf("%s",p.nume);
            printf("pret = "); scanf("%f",&p.pret);
            printf("is = "); scanf("%f",&p.is);
            fwrite(&p,sizeof(p),1,f);
            printf("cod = "); scanf("%d",&p.cod);
        }
        fclose(f);
    }
}
void creare (char numef[]) {
    FILE *f;
    PRODUS p;
    f = fopen(numef, "wb");
    if (f == NULL) {
        printf("eroare");
    }else {
        printf("cod = ");
        scanf("%d",&p.cod);
        while (!feof(stdin)) {
            printf("cant = "); scanf("%d",&p.cant);
            printf("nume = "); scanf("%s",p.nume);
            printf("pret = "); scanf("%f",&p.pret);
            printf("is = "); scanf("%s",&p.is);
            fwrite(&p,sizeof(p),1,f);
            printf("cod = "); scanf("%d",&p.cod);
        }
    }
    fclose(f);
}
int main() {
    char numef[30];
    int nr;
    printf("Nume fisier: ");
    scanf("%s",numef);
    creare(numef);
}