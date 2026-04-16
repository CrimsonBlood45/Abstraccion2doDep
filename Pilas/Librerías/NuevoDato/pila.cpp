#include "pila.h"
#include <iostream>

using namespace std;

void PilaEnteros::push(int valor) {
    NodoEntero nodo;
    nodo.valor = valor;
    pila.push(nodo);
    cout << "[PilaEnteros] push(" << valor << ")  |  tamaño: " << pila.size() << "\n";
}

void PilaEnteros::pop() {
    if (pila.empty())
        cout << "La pila de enteros está vacía." << "\n";
        return;
    cout << "[PilaEnteros] pop()  |  eliminado: " << pila.top().valor << "\n";
    pila.pop();
}

int PilaEnteros::top() const {
    if (pila.empty())
        cout << "La pila de enteros está vacía." << "\n";
        return 0;
    return pila.top().valor;
}

int PilaEnteros::size() const {
    return static_cast<int>(pila.size());
}

bool PilaEnteros::isEmpty() const {
    return pila.empty();
}

void PilaEnteros::mostrar() const {
    stack<NodoEntero> tmp = pila;
    cout << "[PilaEnteros] tope → base: ";
    while (!tmp.empty()) {
        cout << tmp.top().valor << " ";
        tmp.pop();
    }
    cout << "\n";
}