#ifndef PILA_H
#define PILA_H

#include <stack>

class PilaEnteros {
private:
    std::stack<int> pila;

public:
    void push(int valor);
    void pop();
    int  top() const;
    int  size() const;
    bool isEmpty() const;
    void mostrar() const;
};

#endif