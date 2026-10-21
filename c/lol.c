#include <stdio.h>
#include <string.h>
int main() {
    char s[100],sub[100];
    fgets(s,100,stdin);
    fgets(sub,100,stdin);
    char *p=strtok(s," ");
    sub[strlen(sub)-1]='\0';
    while (p!=NULL) {
        if (strcmp(p,sub)!=0){
            printf("%s ",p);
        }
        p=strtok(NULL," ");
    }
}