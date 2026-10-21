//Write a program in C to count the number of words and characters in a file.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
void rez(char numef[], int *nw, int *nc) {
    FILE *f = fopen(numef, "r");
    if (f==NULL)
        printf("eroare vro");
    else {
        char word[40];
        while (!feof(f)) {
            fscanf(f,"%s",word);
            (*nw)++;
            (*nc)=(*nc)+strlen(word);
        }
        fclose(f);
    }
}
int main() {
    char numef[20];
    int nw=0,nc=0;
    printf("nume fisier: : "); scanf("%s",numef);
    rez(numef,&nw,&nc);
    printf("%d %d",nw,nc);
}