#include <stdio.h>
typedef struct
{
    int cant,cod;
    char nume[20],is;
    float pret;

}PRODUS;
int nr_art(FILE *f, int l) {
    long p = ftell(f);
    fseek(f,0,2);
    int n = ftell(f)/l;
    fseek(f,p,0);
    return n;

}
void raportr(char numef[]) {
    FILE *f=fopen(numef,"rb");
    PRODUS p;
    if(f==NULL) {
        printf("Error");
    }else {
        char numer[20];
        printf("numef raport: ");
        scanf("%s",numer);
        FILE *r=fopen(numer,"w");
        if(r==NULL) {
            printf("Error");
        }else {
            fprintf(r,"Cod Cant Nume Pret IS\n");
            fread(&p,sizeof(p),1,f);
            while (!feof(f)) {
                if (p.is == '1' && p.cant == 0) {
                    fprintf(r,"%-3d %-4d %-20s %-4.2f %c\n",p.cod,p.cant,p.nume,p.pret,p.is);
                }
                fread(&p,sizeof(p),1,f);
            }
            fclose(r);
            fclose(f);
        }
    }
}
void modificare(char numef[]) {
    FILE *f=fopen(numef,"rb+");
    PRODUS p;
    if(f==NULL) {
        printf("Error\n");
    }else {
        int cod,cant;
        printf("cod dorit = "); scanf("%d",&cod);
        while (!feof(stdin)) {
            if (cod < nr_art(f,sizeof(p))) {
                fseek(f,cod*sizeof(p),0);
                fread(&p,sizeof(p),1,f);
                if (p.is=='1') {
                    printf("aprovizionare: "); scanf("%d",&cant);
                    p.cant=p.cant+cant;
                    fseek(f,cod*sizeof(p),0);
                    fwrite(&p,sizeof(p),1,f);
                }
            }else
                printf("NU EXISTA");
            printf("cod dorit = "); scanf("%d",&cod);
        }
        fclose(f);
    }
}
void stergere(char numef[]) {
    FILE *f=fopen(numef,"rb+");
    PRODUS p;
    if(f==NULL) {
        printf("Error\n");
    }else {
        int cod,cant;
        printf("cod dorit = "); scanf("%d",&cod);
        while (!feof(stdin)) {
            if (cod < nr_art(f,sizeof(p))) {
                fseek(f,cod*sizeof(p),0);
                fread(&p,sizeof(p),1,f);
                if (p.is=='1') {
                    p.is='0';
                    fseek(f,cod*sizeof(p),0);
                    fwrite(&p,sizeof(p),1,f);
                }else
                    printf("%c",p.is);
            }else
                printf("NU EXISTA.................");
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
            fwrite(&p,sizeof(p),1,f);
            printf("cod = "); scanf("%d",&p.cod);
        }
        fclose(f);
    }
}
int main() {
    char numef[30];
    printf("Nume fisier: ");
    scanf("%s",numef);
    modificare(numef);
}