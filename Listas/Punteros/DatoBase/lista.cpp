#include "lista.h"
#include <iostream>

using namespace std;

ListaEnteros::ListaEnteros() : cantidad(0) {}

void ListaEnteros::push(int valor) {
    if (cantidad >= CAPACIDAD_MAX) {
        cout << "\t[ListaEnteros] Error: La lista está llena.\n";
        return;
    }
    datos[cantidad] = valor;
    cantidad++;
    cout << "\t[ListaEnteros] push(" << valor << ")  |  tamaño: " << cantidad << "\n";
}

void ListaEnteros::pop() {
    if (cantidad == 0) {
        cout << "\t[ListaEnteros] Error: La lista de enteros está vacía.\n";
        return;
    }
    cout << "\t[ListaEnteros] pop()  |  eliminado: " << datos[cantidad - 1] << "\n";
    cantidad--;
}

int ListaEnteros::top() const {
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