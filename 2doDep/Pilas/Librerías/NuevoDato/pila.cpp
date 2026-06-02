#include "pila.h"
#include <iostream>
#include <stack>

using namespace std;

void PilaEnteros::push(int valor) {
    NodoPila nodo;
    nodo.valor = valor;
    pila.push(nodo);
    cout << "\t[PilaEnteros] push(" << valor << ")  |  tamaño: " << pila.size() << "\n";
}

void PilaEnteros::pop() {
    if (pila.empty()) {
        cout << "La pila de enteros está vacía.\n";
        return;
    }
    cout << "\t[PilaEnteros] pop()  |  eliminado: " << pila.top().valor << "\n";
    pila.pop();
}

int PilaEnteros::top() const {
    if (pila.empty()) {
        cout << "La pila de enteros está vacía.\n";
        return 0;
    }
    return pila.top().valor;
}

int PilaEnteros::size() const {
    return static_cast<int>(pila.size());
}

bool PilaEnteros::isEmpty() const {
    return pila.empty();
}

void PilaEnteros::mostrar() const {
    cout << "\t[PilaEnteros] tope → base: ";
    stack<NodoPila> aux = pila;
    while (!aux.empty()) {
        cout << aux.top().valor << " ";
        aux.pop();
    }
    cout << "\n";
}
