#include "lista.h"
#include <iostream>
#include <stack>

using namespace std;

void ListaEnteros::push(int valor) {
    pila.push(valor);
    cout << "\t[ListaEnteros] push(" << valor << ")  |  tamaño: " << pila.size() << "\n";
}

void ListaEnteros::pop() {
    if (pila.empty()) {
        cout << "\t[ListaEnteros] Error: La lista de enteros está vacía.\n";
        return;
    }
    cout << "\t[ListaEnteros] pop()  |  eliminado: " << pila.top() << "\n";
    pila.pop();
}

int ListaEnteros::top() const {
    if (pila.empty()) {
        cout << "\t[ListaEnteros] Error: La lista de enteros está vacía.\n";
        return 0;
    }
    return pila.top();
}

int ListaEnteros::size() const {
    return static_cast<int>(pila.size());
}

bool ListaEnteros::isEmpty() const {
    return pila.empty();
}

void ListaEnteros::mostrar() const {
    cout << "[ListaEnteros] tope → base: ";
    stack<int> aux = pila;
    while (!aux.empty()) {
        cout << aux.top() << " ";
        aux.pop();
    }
    cout << "\n";
}
