#include "pila.h"
#include <iostream>

using namespace std;

PilaEnteros::PilaEnteros() : cantidad(0) {}

void PilaEnteros::push(int valor) {
    if (cantidad >= CAPACIDAD_MAX) {
        cout << "\t[PilaEnteros] Error: La pila está llena.\n";
        return;
    }
    nodos[cantidad].valor = valor;
    cantidad++;
    cout << "\t[PilaEnteros] push(" << valor << ")  |  tamaño: " << cantidad << "\n";
}

void PilaEnteros::pop() {
    if (cantidad == 0) {
        cout << "La pila de enteros está vacía.\n";
        return;
    }
    cout << "\t[PilaEnteros] pop()  |  eliminado: " << nodos[cantidad - 1].valor << "\n";
    cantidad--;
}

int PilaEnteros::top() const {
    if (cantidad == 0) {
        cout << "La pila de enteros está vacía.\n";
        return 0;
    }
    return nodos[cantidad - 1].valor;
}

int PilaEnteros::size() const {
    return cantidad;
}

bool PilaEnteros::isEmpty() const {
    return cantidad == 0;
}

void PilaEnteros::mostrar() const {
    cout << "\t[PilaEnteros] tope → base: ";
    if (cantidad == 0) {
        cout << "(vacía)\n";
        return;
    }
    for (int i = cantidad - 1; i >= 0; i--) {
        cout << nodos[i].valor << " ";
    }
    cout << "\n";
}
