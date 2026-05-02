#ifndef PILA_H
#define PILA_H
#include "../../pilaadt.h"

class PilaEnteros : public PilaADT {
private:
    int*  datos;
    int   cantidad;
    int   capacidad;

    void redimensionar();

public:
    PilaEnteros(int cap = 4);
    ~PilaEnteros();

    void push(int valor) override;
    void pop()           override;
    int  top()     const override;
    int  size()    const override;
    bool isEmpty() const override;
    void mostrar() const override;
};

#endif
