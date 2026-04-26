#include "lista.h"
#include <iostream>
#include <stack>

using namespace std;

void ListaEnteros::push(int valor) {
    NodoEntero nodo;
    nodo.valor = valor;
    pila.push(nodo);
    cout << "\t[ListaEnteros] push(" << valor << ")  |  tamaño: " << pila.size() << "\n";
}

void ListaEnteros::pop() {
    if (pila.empty()) {
        cout << "La lista de enteros está vacía.\n";
        return;
    }
    cout << "\t[ListaEnteros] pop()  |  eliminado: " << pila.top().valor << "\n";
    pila.pop();
}

int ListaEnteros::top() const {
    if (pila.empty()) {
        cout << "La lista de enteros está vacía.\n";
        return 0;
    }
    return pila.top().valor;
}

int ListaEnteros::size() const {
    return static_cast<int>(pila.size());
}

bool ListaEnteros::isEmpty() const {
    return pila.empty();
}

void ListaEnteros::mostrar() const {
    cout << "\t[ListaEnteros] tope → base: ";
    stack<NodoEntero> aux = pila;
    while (!aux.empty()) {
        cout << aux.top().valor << " ";
        aux.pop();
    }
    cout << "\n";
}
