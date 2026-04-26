#ifndef LISTA_H
#define LISTA_H
#include "../../listaadt.h"

class Nodo {
public:
    int   dato;
    Nodo* siguiente;
    Nodo(int valor, Nodo* sig = nullptr) : dato(valor), siguiente(sig) {}
};

class ListaEnteros : public ListaADT {
private:
    Nodo* cabeza;
    Nodo* cola;
    int   cantidad;

public:
    ListaEnteros();
    ~ListaEnteros();

    void push(int valor) override;
    void pop()           override;
    int  top()     const override;
    int  size()    const override;
    bool isEmpty() const override;
    void mostrar() const override;
};

#endif