//Write a program in C to delete a specific line from a file.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
void rez(char numef[],int l ) {
    int k=0;
    FILE *f1 = fopen(numef, "r+");
    FILE *f2 = fopen("k.txt", "w+");
    if (f1 == NULL || f2 == NULL) {
        printf("Eroare\n");
    }else {
        char line[30];
        while (!feof(f1)) {
            fgets(line,30,f1);
            k++;
            if (l!=k)
                fputs(line,f2);
        }
        fseek(f1,0,0);
        fseek(f2,0,0);
        while (!feof(f2)) {
            fgets(line,30,f2);
            fputs(line,f1);
        }
        fclose(f1);
        fclose(f2);
    }

}
int main() {
    char numef[20];
    int l;
    printf("nume fisier: : "); scanf("%s",numef);
    printf("linie: "); scanf("%d",&l);
    rez(numef,l);
}