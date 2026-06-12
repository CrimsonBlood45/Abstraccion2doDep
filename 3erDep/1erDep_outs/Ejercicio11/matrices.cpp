#include "matrices.h"
#include <iostream>

using namespace std;

Matrices::Matrices(){}

Matrices::~Matrices(){}

void Matrices::leerA(){

    cout << "Matriz A" << endl;

    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){

            cout << "Ingrese valor: ";
            cin >> A[i][j];

        }
    }

}

void Matrices::leerB(){

    cout << "Matriz B" << endl;

    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){

            cout << "Ingrese valor: ";
            cin >> B[i][j];

        }
    }

}

void Matrices::multiplicarConstante(){

    int k;

    cout << "Ingrese constante: ";
    cin >> k;

    cout << "Resultado A * constante" << endl;

    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){

            int resultado = A[i][j] * k;
            cout << resultado << " ";

        }

        cout << endl;
    }

}

void Matrices::multiplicarMatrices(){

    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){

            C[i][j] = 0;

            for(int k=0; k<2; k++){

                C[i][j] = C[i][j] + (A[i][k] * B[k][j]);

            }

        }
    }

    cout << "Resultado A * B" << endl;

    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){

            cout << C[i][j] << " ";

        }

        cout << endl;
    }

}