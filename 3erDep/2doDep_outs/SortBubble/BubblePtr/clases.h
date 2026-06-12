#ifndef CLASES_H
#define CLASES_H

#include <string>
using namespace std;

class Persona {
private:
    string nombre;
    int edad;
public:
    void leer();
    int getEdad();
    void mostrar();
};

class Ordenador {
public:
    void burbujaIndirectaEnteros(int arr[], int* idx, int n);
    void burbujaIndirectaChars(char arr[], int* idx, int n);
    void burbujaIndirectaPersonas(Persona arr[], int* idx, int n);
};

#endif
