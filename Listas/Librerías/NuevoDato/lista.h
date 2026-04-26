#ifndef LISTA_H
#define LISTA_H
#include <list>
#include "../../listaadt.h"

class NodoEntero {
public:
    int valor;
};

class ListaEnteros : public ListaADT {
private:
    std::list<NodoEntero> lista;

public:
    void push(int valor) override;
    void pop() override;
    int  top() const override;
    int  size() const override;
    bool isEmpty() const override;
    void mostrar() const override;
};

#endif