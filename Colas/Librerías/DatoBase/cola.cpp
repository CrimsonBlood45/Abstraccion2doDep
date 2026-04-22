#include "cola.h"
#include <iostream>
#include <stdexcept>
using namespace std;

void ColaEnteros::push(int valor) {
    cola.push(valor);
    cout << "[ColaEnteros] push(" << valor << ")  |  tamaño: " << cola.size() << "\n";
}

void ColaEnteros::pop() {
    if (cola.empty())
        throw underflow_error("La cola de enteros está vacía.");
    cout << "[ColaEnteros] pop()  |  eliminado: " << cola.front() << "\n";
    cola.pop();
}

int ColaEnteros::front() const {
    if (cola.empty())
        throw underflow_error("La cola de enteros está vacía.");
    return cola.front();
}

int ColaEnteros::size() const {
    return static_cast<int>(cola.size());
}

bool ColaEnteros::isEmpty() const {
    return cola.empty();
}

void ColaEnteros::mostrar() const {
    queue<int> tmp = cola;
    cout << "[ColaEnteros] frente → final: ";
    while (!tmp.empty()) {
        cout << tmp.front() << " ";
        tmp.pop();
    }
    cout << "\n";
}