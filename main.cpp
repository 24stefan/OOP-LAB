#include <iostream>
#include "Matrica.hpp"
using namespace std;

int main () {
 int n, m;

 cin >> m >> n;

 Matrica A(m, n, "A");

 A.unesiMat();



cout << "\nSuma 1. kolone" << A.sumaKolone(1);
cout << "\nSuma 3. kolone" << A.sumaKolone(3);

cout << "\nSuma 2. reda" << A.sumaReda(2);
cout << "\nSuma 3. reda" << A.sumaReda(3) << endl;

A.prikaz();


    return 0;
}