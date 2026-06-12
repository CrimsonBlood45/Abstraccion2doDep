#ifndef LISTA_H
#define LISTA_H
#include "../../listaadt.h"

#define CAPACIDAD_MAX 100

class NodoEntero {
public:
    int valor;
};

class ListaEnteros : public ListaADT {
private:
    NodoEntero nodos[CAPACIDAD_MAX];
    int cantidad;

public:
    ListaEnteros();

    void insertAt(int valor) override;
    void removeAt()     override;
    int  get()     const override;
    int  size()    const override;
    bool isEmpty() const override;
    void mostrar() const override;
};

#endif
