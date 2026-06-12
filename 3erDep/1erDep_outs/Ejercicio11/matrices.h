#ifndef MATRICES_H
#define MATRICES_H

class Matrices{

private:
    int A[2][2];
    int B[2][2];
    int C[2][2];

public:

    Matrices();
    ~Matrices();

    void leerA();
    void leerB();
    void multiplicarConstante();
    void multiplicarMatrices();

};

#endif