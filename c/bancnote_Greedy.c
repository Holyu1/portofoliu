#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define INFINIT 1000000000
int main() {
   int bancn[7]={500,200,50,20,10,5,1};
   int suma,i=0;
   scanf("%d",&suma);
   while (suma!=0) {
      if (suma/bancn[i]==0)
         i++;
      else {
         int aux = suma/bancn[i];
         suma=suma-aux*bancn[i];
         while (aux!=0) {
            printf("%d ",bancn[i]);
            aux=aux-1;
         }
         i++;
      }
   }

}