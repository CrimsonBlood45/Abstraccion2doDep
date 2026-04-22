#ifndef COLA_H
#define COLA_H

#include <queue>
#include "../../colaadt.h"

struct NodoEntero {
    int valor;
};

class ColaEnteros : public ColaADT{
private:
    std::queue<NodoEntero> cola;

public:
    void push(int valor) override;
    void pop() override;
    int  front() const override;
    int  size() const override;
    bool isEmpty() const override;
    void mostrar() const override;
};

#endif