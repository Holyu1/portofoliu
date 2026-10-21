#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS
struct STUD {
    int nr_mat,an,grupa,nr_note,note[15];
    char nume[30];
}p;
void consultare_ex2(char numef[]) {
    FILE *f=fopen(numef,"r");
    if (!f)
        printf("eroare");
    else {
        printf("nr mat: ");
        scanf("%d",&p.nr_mat);
        while (!feof(stdin)) {
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
            fwrite(&p,sizeof(p),1,f);
            fwrite("\n",1,1,f);
            printf("nr mat: ");
            scanf("%d",&p.nr_mat);
        }
        fclose(f);
    }
}
int main() {
    char s[100];
    printf("numefisier: ");
    gets(s);
    consultare_ex2(s);
}