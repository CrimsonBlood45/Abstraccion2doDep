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
    void insertAt(int valor) override;
    void removeAt() override;
    int  get() const override;
    int  size() const override;
    bool isEmpty() const override;
    void mostrar() const override;
};

#endif