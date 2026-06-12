#include "pila.h"
#include <iostream>
#include <stack>

using namespace std;

void PilaEnteros::push(int valor) {
    pila.push(valor);
    cout << "\t[PilaEnteros] push(" << valor << ")  |  tamaño: " << pila.size() << "\n";
}

void PilaEnteros::pop() {
    if (pila.empty()) {
        cout << "\t[PilaEnteros] Error: La pila de enteros está vacía.\n";
        return;
    }
    cout << "\t[PilaEnteros] pop()  |  eliminado: " << pila.top() << "\n";
    pila.pop();
}

int PilaEnteros::top() const {
    if (pila.empty()) {
        cout << "\t[PilaEnteros] Error: La pila de enteros está vacía.\n";
        return 0;
    }
    return pila.top();
}

int PilaEnteros::size() const {
    return static_cast<int>(pila.size());
}

bool PilaEnteros::isEmpty() const {
    return pila.empty();
}

void PilaEnteros::mostrar() const {
    cout << "[PilaEnteros] tope → base: ";
    stack<int> aux = pila;
    while (!aux.empty()) {
        cout << aux.top() << " ";
        aux.pop();
    }
    cout << "\n";
}
