#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS
struct STUD {
    char nume[30];
    int nr_mat,an,grupa,nr_note,note[15];
}p;
void creare(char numef[]) {
    FILE *f=fopen(numef,"wb");
    if (!f)
        printf("eroare");
    else {
        printf("nr mat: ");
        scanf("%d",&p.nr_mat);
        while (!feof(stdin)) {
            getchar();
            printf("an: ");
            scanf("%d",&p.an);
            printf("grupa: ");
            scanf("%d",&p.grupa);
            printf("nr_note: ");
            scanf("%d",&p.nr_note);
            printf("note: ");
            for (int i = 0;i<p.nr_note;i++)
                scanf("%d",&p.note[i]);
            printf("nume: ");
            scanf("%s",p.nume);
            fwrite(&p.nr_mat,sizeof(int),1,f);
            fwrite(&p.an,sizeof(int),1,f);
            fwrite(&p.grupa,sizeof(int),1,f);
            fwrite(&p.nr_note,sizeof(int),1,f);
            fwrite(&p.note,sizeof(int),1,f);
            fwrite(&p.nume,strlen(p.nume),1,f);
            printf("nr mat: ");
            scanf("%d",&p.nr_mat);
        }
        fclose(f);
    }
}
int main() {
    char s[100];
    printf("numefisier: ");
    scanf("%s",s);
    creare(s);
}

