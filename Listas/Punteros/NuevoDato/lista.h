#ifndef LISTA_H
#define LISTA_H
#include <iostream>
using namespace std;

class Lista {
private:
    struct Elemento {
        int valor;
        bool ocupado;
    };

    struct Bloque {
        Elemento* elementos;
        int capacidad;
        int tam;
    };

    Bloque bloque;

    void redimensionar();

public:
    Lista(int cap = 5);
    ~Lista();
    void insertar(int valor);
    void eliminar(int valor);
    void mostrar();
};

#endif