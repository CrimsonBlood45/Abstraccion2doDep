#ifndef COLA_H
#define COLA_H

#include <queue>

struct NodoEntero {
    int valor;
};

class ColaEnteros {
private:
    std::queue<NodoEntero> cola;

public:
    void push(int valor);
    void pop();
    int  front() const;
    int  size() const;
    bool isEmpty() const;
    void mostrar() const;
};

#endif