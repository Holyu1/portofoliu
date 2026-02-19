#include <stdio.h>
/*
   pt fisiere nonbinare: fscanf, fprintf
   pt fisiere binare: fread, fwrite
   pt astea nu conteaza:ftell, fseek
  */
int main()
{
    char a;
    FILE *f = fopen("dooo.txt", "r");
    for (int i = 0;i<=5;i++) {
        fscanf(f, "%c", &a);
        printf("%c",a);
        fseek(f,i+1,0);
    }
    fclose(f);
}