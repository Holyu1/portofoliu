#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int nr_art(FILE *f, int l) {
    int p = ftell(f);
    fseek(f,0,2);
    int n= ftell(f)/l;
    fseek(f,p,0);
    return n;
}
