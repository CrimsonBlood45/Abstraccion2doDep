#ifndef LISTA_H
#define LISTA_H
#include "../../listaadt.h"

class NodoEntero {
public:
    int         valor;
    NodoEntero* siguiente;

    NodoEntero(int val, NodoEntero* sig = nullptr)
        : valor(val), siguiente(sig) {}
};

class ListaEnteros : public ListaADT {
private:
    NodoEntero* tope;
    int         cantidad;

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
