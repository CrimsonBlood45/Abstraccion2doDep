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
    string getNombre();
    void mostrar();
};

class Ordenador {
public:
    void burbujaEnteros(int arr[], int n);
    void burbujaChars(char arr[], int n);
    void burbujaPersonas(Persona arr[], int n);
};

#endif
