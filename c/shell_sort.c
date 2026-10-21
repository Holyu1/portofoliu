#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
void sort_shell(int v[], int l)
{
    int i, j, inc;
    double a;
    for (inc = l / 2; inc > 0; inc = inc / 2)
        for (i = 0; i <= l-1; i++)
            if(i+inc<=l-1)
                if(v[i]>v[i+inc])
                {
                    a = v[i];
                    v[i] = v[i+ inc];
                    v[i + inc] = a;
                }
}


void main()
{
    int n, i;
    int v[1000];
    printf("n="); scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("v[%d]=", i);
        scanf("%d", &v[i]);
    }
    sort_shell(v, n);
    printf("Vectorul sortat\n");
    for (i = 0; i < n; i++) printf("%d ", v[i]);
}
