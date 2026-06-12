#ifndef PILA_H
#define PILA_H
#include "../../pilaadt.h"

class NodoPila {
public:
    int         valor;
    NodoPila* siguiente;

    NodoPila(int val, NodoPila* sig = nullptr)
        : valor(val), siguiente(sig) {}
};

class PilaEnteros : public PilaADT {
private:
    NodoPila* tope;
    int         cantidad;

public:
    PilaEnteros();
    ~PilaEnteros();

    void push(int valor) override;
    void pop()           override;
    int  top()     const override;
    int  size()    const override;
    bool isEmpty() const override;
    void mostrar() const override;
};

#endif
