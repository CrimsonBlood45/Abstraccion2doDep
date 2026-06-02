#include "pila.h"
#include <iostream>

using namespace std;

PilaEnteros::PilaEnteros() : cantidad(0) {}

void PilaEnteros::push(int valor) {
    if (cantidad >= CAPACIDAD_MAX) {
        cout << "\t[PilaEnteros] Error: La pila está llena.\n";
        return;
    }
    datos[cantidad] = valor;
    cantidad++;
    cout << "\t[PilaEnteros] push(" << valor << ")  |  tamaño: " << cantidad << "\n";
}

void PilaEnteros::pop() {
    if (cantidad == 0) {
        cout << "\t[PilaEnteros] Error: La pila de enteros está vacía.\n";
        return;
    }
    cout << "\t[PilaEnteros] pop()  |  eliminado: " << datos[cantidad - 1] << "\n";
    cantidad--;
}

int PilaEnteros::top() const {
    if (cantidad == 0) {
        cout << "\t[PilaEnteros] Error: La pila de enteros está vacía.\n";
        return 0;
    }
    return datos[cantidad - 1];
}

int PilaEnteros::size() const {
    return cantidad;
}

bool PilaEnteros::isEmpty() const {
    return cantidad == 0;
}

void PilaEnteros::mostrar() const {
    cout << "[PilaEnteros] tope → base: ";
    if (cantidad == 0) {
        cout << "(vacía)\n";
        return;
    }
    for (int i = cantidad - 1; i >= 0; i--) {
        cout << datos[i] << " ";
    }
    cout << "\n";
}
