/******************************************************************************

Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n,sortat=0,aux;
    cin >> n;
    int x[n],i;
    for (i=0;i<n;i++)
        cin >> x[i];
    while (sortat == 0) {
        sortat = 1;
        for (i=0;i<=n-2;i++)
            if (x[i] > x[i+1]) {
                aux=x[i];
                x[i]=x[i+1];
                x[i+1]=aux;
                sortat=0;
            }
    }
    for (i=0;i<n;i++) {
        cout << x[i] << " ";
    }


}