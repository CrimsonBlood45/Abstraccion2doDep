#include "cola.h"
#include <iostream>
using namespace std;

void ColaEnteros::enqueue(int valor) {
    cola.push(valor);
    cout << "\t[ColaEnteros] enqueue(" << valor << ")  |  tamaño: " << cola.size() << "\n";
}

void ColaEnteros::dequeue() {
    if (cola.empty())
        cout << "\t[ColaEnteros] La cola de enteros está vacía.\n";
    cout << "\t[ColaEnteros] dequeue()  |  eliminado: " << cola.front() << "\n";
    cola.pop();
}

int ColaEnteros::front() const {
    if (cola.empty())
        cout << "\t[ColaEnteros] La cola de enteros está vacía.\n";
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
    cout << "\t[ColaEnteros] frente → final: ";
    while (!tmp.empty()) {
        cout << tmp.front() << " ";
        tmp.pop();
    }
    cout << "\n";
}