#include "cola.h"
#include <iostream>
#include <stdexcept>
using namespace std;

void ColaEnteros::push(int valor) {
    NodoEntero nodo;
    nodo.valor = valor;
    cola.push(nodo);
    cout << "[ColaEnteros] push(" << valor << ")  |  tamaño: " << cola.size() << "\n";
}

void ColaEnteros::pop() {
    if (cola.empty())
        throw underflow_error("La cola de enteros está vacía.");
    cout << "[ColaEnteros] pop()  |  eliminado: " << cola.front().valor << "\n";
    cola.pop();
}

int ColaEnteros::front() const {
    if (cola.empty())
        throw underflow_error("La cola de enteros está vacía.");
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
    cout << "[ColaEnteros] frente → final: ";
    while (!tmp.empty()) {
        cout << tmp.front().valor << " ";
        tmp.pop();
    }
    cout << "\n";
}