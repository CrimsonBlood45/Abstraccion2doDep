#ifndef LISTA_H
#define LISTA_H
#include <stack>
#include "../../listaadt.h"

class NodoEntero {
public:
    int valor;
};

class ListaEnteros : public ListaADT {
private:
    std::stack<NodoEntero> pila;
public:
    void push(int valor) override;
    void pop()           override;
    int  top()     const override;
    int  size()    const override;
    bool isEmpty() const override;
    void mostrar() const override;
};

#endif
