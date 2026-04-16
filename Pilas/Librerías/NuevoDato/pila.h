#ifndef PILA_H
#define PILA_H

#include <stack>

struct NodoEntero {
    int valor;
};

class PilaEnteros {
private:
    std::stack<NodoEntero> pila;

public:
    void push(int valor);
    void pop();
    int  top() const;
    int  size() const;
    bool isEmpty() const;
    void mostrar() const;
};

#endif