#include "cola.h"
#include <iostream>
using namespace std;

void ColaEnteros::push(int valor) {
    NodoEntero nodo;
    nodo.valor = valor;
    cola.push(nodo);
    cout << "\t[ColaEnteros] push(" << valor << ")  |  tamaño: " << cola.size() << "\n";
}

void ColaEnteros::pop() {
    if (cola.empty())
        cout << "\t[ColaEnteros] La cola de enteros está vacía.\n";
    cout << "\t[ColaEnteros] pop()  |  eliminado: " << cola.front().valor << "\n";
    cola.pop();
}

int ColaEnteros::front() const {
    if (cola.empty())
        cout << "\t[ColaEnteros] La cola de enteros está vacía.\n";
    return cola.front().valor;
}

int ColaEnteros::size() const {
    return static_cast<int>(cola.size());
}

bool ColaEnteros::isEmpty() const {
    return cola.empty();
}

void ColaEnteros::mostrar() const {
    queue<NodoEntero> tmp = cola;
    cout << "\t[ColaEnteros] frente → final: ";
    while (!tmp.empty()) {
        cout << tmp.front().valor << " ";
        tmp.pop();
    }
    cout << "\n";
}