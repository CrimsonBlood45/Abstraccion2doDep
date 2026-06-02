#ifndef PILA_H
#define PILA_H
#include "../../pilaadt.h"

#define CAPACIDAD_MAX 100

class NodoPila {
public:
    int valor;
};

class PilaEnteros : public PilaADT {
private:
    NodoPila nodos[CAPACIDAD_MAX];
    int cantidad;

public:
    PilaEnteros();

    void push(int valor) override;
    void pop()           override;
    int  top()     const override;
    int  size()    const override;
    bool isEmpty() const override;
    void mostrar() const override;
};

#endif
