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
    int  particionEnteros(int arr[], int* idx, int inicio, int fin);
    void quickSortEnteros(int arr[], int* idx, int inicio, int fin);

    int  particionChars(char arr[], int* idx, int inicio, int fin);
    void quickSortChars(char arr[], int* idx, int inicio, int fin);

    int  particionPersonas(Persona arr[], int* idx, int inicio, int fin);
    void quickSortPersonas(Persona arr[], int* idx, int inicio, int fin);
};

#endif
