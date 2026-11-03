#ifndef MATRICA_H
#define MATRICA_H

class Matrica {
private:
    double** mat;
    int n, m;
    char* naziv;
public:
    Matrica();
    Matrica(int m, int n, const char* naziv); 
    ~Matrica();

    inline int getM() {
        return m;
    }
    inline int getN() {
        return n; 
     }

    double sumaReda(int red);
    double sumaKolone(int kol);
    void unesiMat();

    static Matrica* kronker(Matrica& A, Matrica& B);
    static Matrica* proiz(Matrica& A, Matrica& B);

    void prikaz();

};

#endif 