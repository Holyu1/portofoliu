/******************************************************************************

Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int n,sortat=0,aux;
    cin >> n;
    int i;
    vector <int> x;
    for (i=0;i<n;i++) {
        int y;
        cin >> y;
        x.push_back(y);
    }
    sort(x.begin(),x.end(), [&](int a, int b) {
        return a<b;
    });
    for (i = 0; i <= n-1; i++) {
        cout << x[i] << " ";
    }


}