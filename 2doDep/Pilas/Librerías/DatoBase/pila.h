#ifndef PILA_H
#define PILA_H
#include <stack>
#include "../../pilaadt.h"

class PilaEnteros : public PilaADT {
private:
    std::stack<int> pila;
public:
    void push(int valor) override;
    void pop()           override;
    int  top()     const override;
    int  size()    const override;
    bool isEmpty() const override;
    void mostrar() const override;
};

#endif
