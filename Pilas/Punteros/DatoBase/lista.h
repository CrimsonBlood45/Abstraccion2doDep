#ifndef LISTA_H
#define LISTA_H
#include "../../listaadt.h"

class ListaEnteros : public ListaADT {
private:
    int*  datos;
    int   cantidad;
    int   capacidad;

    void redimensionar();

public:
    ListaEnteros(int cap = 4);
    ~ListaEnteros();

    void push(int valor) override;
    void pop()           override;
    int  top()     const override;
    int  size()    const override;
    bool isEmpty() const override;
    void mostrar() const override;
};

#endif
