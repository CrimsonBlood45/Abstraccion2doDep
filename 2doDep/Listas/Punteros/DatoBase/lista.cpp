#include "lista.h"
#include <iostream>

using namespace std;

ListaEnteros::ListaEnteros() : cantidad(0) {}

void ListaEnteros::insertAt(int valor) {
    if (cantidad >= CAPACIDAD_MAX) {
        cout << "\t[ListaEnteros] Error: La lista está llena.\n";
        return;
    }
    datos[cantidad] = valor;
    cantidad++;
    cout << "\t[ListaEnteros] insertAt(" << valor << ")  |  tamaño: " << cantidad << "\n";
}

void ListaEnteros::removeAt() {
    if (cantidad == 0) {
        cout << "\t[ListaEnteros] Error: La lista de enteros está vacía.\n";
        return;
    }
    cout << "\t[ListaEnteros] removeAt()  |  eliminado: " << datos[cantidad - 1] << "\n";
    cantidad--;
}

int ListaEnteros::get() const {
    if (cantidad == 0) {
        cout << "\t[ListaEnteros] Error: La lista de enteros está vacía.\n";
        return 0;
    }
    return datos[cantidad - 1];
}

int ListaEnteros::size() const {
    return cantidad;
}

bool ListaEnteros::isEmpty() const {
    return cantidad == 0;
}

void ListaEnteros::mostrar() const {
    cout << "[ListaEnteros] tope → base: ";
    if (cantidad == 0) {
        cout << "(vacía)\n";
        return;
    }
    for (int i = cantidad - 1; i >= 0; i--) {
        cout << datos[i] << " ";
    }
    cout << "\n";
}