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
    void mergeEnteros(int arr[], int izq, int mid, int der);
    void mergeSortEnteros(int arr[], int izq, int der);

    void mergeChars(char arr[], int izq, int mid, int der);
    void mergeSortChars(char arr[], int izq, int der);

    void mergePersonas(Persona arr[], int izq, int mid, int der);
    void mergeSortPersonas(Persona arr[], int izq, int der);
};

#endif
