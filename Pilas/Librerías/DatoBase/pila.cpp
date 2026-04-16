#include "pila.h"
#include <iostream>

using namespace std;

void PilaEnteros::push(int valor) {
    pila.push(valor);
    cout << "[PilaEnteros] push(" << valor << ")  |  tamaño: " << pila.size() << "\n";
}

void PilaEnteros::pop() {
    if (pila.empty())
        cout << "La pila de enteros está vacía." << "\n";
        return;
    cout << "[PilaEnteros] pop()  |  eliminado: " << pila.top() << "\n";
    pila.pop();
}

int PilaEnteros::top() const {
    if (pila.empty())
        cout << "Error: La pila de enteros está vacía." << endl;
        return 0;
    return pila.top();
}

int PilaEnteros::size() const {
    return static_cast<int>(pila.size());
}

bool PilaEnteros::isEmpty() const {
    return pila.empty();
}

void PilaEnteros::mostrar() const {
    stack<int> tmp = pila;
    cout << "[PilaEnteros] tope → base: ";
    while (!tmp.empty()) {
        cout << tmp.top() << " ";
        tmp.pop();
    }
    cout << "\n";
}