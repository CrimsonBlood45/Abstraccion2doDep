#ifndef LISTA_H
#define LISTA_H

#include <list>

struct NodoEntero {
    int valor;
};

class ListaEnteros {
private:
    std::list<NodoEntero> lista; // el final (back) será el tope

public:
    void push(int valor);
    void pop();
    int  top() const;
    int  size() const;
    bool isEmpty() const;
    void mostrar() const;
};

#endif