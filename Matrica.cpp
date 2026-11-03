#include <iostream>
#include "Matrica.hpp"
#include <cstring>

using namespace std;


Matrica::Matrica(){
    m = 20;
    n = 20;
    mat = new double*[m];
    for( int i = 0; i < m; i++)
      mat[i] = new double [n];
    naziv = new char[8];
    strcpy(naziv, "Matrica");

}

Matrica::Matrica(int m, int n, const char* naziv){
    this->m = m;
    this->n = n;

    mat = new double*[m];
    for(int i = 0; i < m; i++) {
        mat[i] = new double[n]();
    }

   this->naziv= new char[strlen(naziv) + 1];
   strcpy(this->naziv, naziv);


}

Matrica::~Matrica() {
     for(int i = 0; i < m; i++) 
      delete[] mat[i];

    delete[] mat;
    delete[] naziv;
}

// ----   ------------



double Matrica::sumaReda(int red) {
    double suma = 0;

    for(int i = 0; i < n; i++)
     suma += mat[red - 1][i];

    return suma;
}

double Matrica::sumaKolone(int kol){
    double suma = 0;

    for( int i = 0; i < m; i++) 
        suma += mat[i][kol-1];

    return suma;
    
}

void Matrica::unesiMat() {
    
    for(int i = 0; i < m; i++)
     for(int j = 0; j < n; j++)
        cin >> mat[i][j];  
}

void  Matrica::prikaz() {
    for(int i = 0; i < m; i++) {
       for(int j = 0; j < n; j++)
        cout << mat[i][j] << " "; 
    cout << endl;
    }


}

 Matrica* Matrica::proiz(Matrica& A, Matrica& B) {
    if(A.n != B.m) { // mat Amxn i B mxn
        cout << "Matrice nisu kompatibline za mnozenje";
        return nullptr;
    }

    Matrica* C = new Matrica(A.m, B.n, "Proizvod");

    for(int i = 0; i < A.m; i++) {
        for(int j = 0; j < B.n; j++) {
            C->mat[i][j] = 0;
        
            for(int l = 0; l < A.n; l++) {
                C->mat[i][j] += A.mat[i][l] * B.mat[l][j];
            }
        }
    }

 return C;
}


Matrica* Matrica::kronker(Matrica& A, Matrica& B) {
    Matrica* C= new Matrica(A.m * B.m, A.n * B.n, "KronekerovProiz" );

    for(int i = 0; i  < A.m; i++) {
        for(int j = 0; j < A.n; j++) {
            for(int k = 0; k < B.m; k++) {
                for (int l = 0; l < B.n; l++) {
                    C->mat[i * B.m + k][j * B.n + l] = A.mat[i][j] * B.mat[k][l];
                }
            }
        }
    }
    return C;

}
