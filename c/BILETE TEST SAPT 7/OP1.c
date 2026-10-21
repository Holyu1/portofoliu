#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
typedef struct {
    char punct;
}TEMA;
typedef struct {
    int nrmat,grupa;
    char nume[30],pprob[1],pex[1],is;
    TEMA tema[11];
}STUD;
int nr_art(FILE *f, int l) {
    long p = ftell(f);
    fseek(f,0,2);
    int n = ftell(f)/l;
    fseek(f,p,0);
    return n;
}
void adaugare (char numef[]) {
    FILE *f = fopen(numef,"rb+");
    STUD s;
    if (f == NULL) {
        printf("eroare");
    }else {
        int nrt,nrm,pct;
        printf("student a obtinut puncte la tema ");
        scanf("%d %d %d",&nrm,&pct,&nrt);
        while (!feof(stdin)) {
            if (s.is == '1' && nrm < nr_art(f,sizeof(s))) {
                fseek(f,nrm*sizeof(s),0);
                fread(&s,sizeof(s),1,stdin);
                s.tema[nrt].punct=pct;
                fseek(f,nrm*sizeof(s),0);
                fwrite(&s,sizeof(s),1,stdout);
            }
            printf("student a obtinut puncte la tema ");
            scanf("%d %d %d",&nrm,&pct,&nrt);
        }
    }
}
void raport(char numef[]) {
    FILE *f = fopen(numef,"rb");
    STUD s;
    if (f == NULL) {
        printf("error");
    }else {
        char numer[30];
        printf("nume raport: "); scanf("%s",numer);
        FILE *r = fopen(numer,"w");
        if (r==NULL)
            printf("error");
        else {
            fprintf(r,"Nr. matricol Nume Grupa Puncte proba practica Puncte pentru teme Puncte pentru examen\n");
            fread(&s,sizeof(s),1,f);
            while (!feof(f)) {
                fprintf(r,"%c \n",s.tema[0].punct);
                fread(&s,sizeof(s),1,f);
            }
            fclose(r);
            fclose(f);
        }

    }
}
void creare (char numef[]) {
    FILE *f;
    STUD s;
    f = fopen(numef, "wb");
    if (f == NULL) {
        printf("eroare");
    }else {
        printf("nrmat = ");
        scanf("%d",&s.nrmat);
        while (!feof(stdin)) {
           printf("grupa: "); scanf("%d",&s.grupa);
           printf("nume: "); scanf("%s",s.nume);
           printf("puncte proba practica: "); scanf("%s",s.pprob);
           printf("puncte examen: "); scanf("%s",s.pex);
           printf("is: "); scanf(" %c",&s.is);
           for (int i = 1;i<=10;i++) {
               s.tema[i].punct='0';
           }
           fwrite(&s,sizeof(s),1,f);
           printf("nrmat: "); scanf("%d",&s.nrmat);
        }
        fclose(f);
    }
}
int main() {
    char numef[30];
    printf("nume fisier: "); scanf("%s",numef);
    //adaugare (numef);
    raport(numef);
    //creare (numef);
}

