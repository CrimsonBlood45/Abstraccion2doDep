#include "lista.h"
#include <iostream>

using namespace std;

ListaEnteros::ListaEnteros() : cabeza(nullptr), cola(nullptr), cantidad(0) {}

ListaEnteros::~ListaEnteros() {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        Nodo* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
    cabeza   = nullptr;
    cola     = nullptr;
    cantidad = 0;
}

void ListaEnteros::push(int valor) {
    Nodo* nuevo = new Nodo(valor);

    if (cola == nullptr) {
        cabeza = nuevo;
        cola   = nuevo;
    } else {
        cola->siguiente = nuevo;
        cola = nuevo;
    }

    cantidad++;
    cout << "\t[ListaEnteros] push(" << valor << ")  |  tamaño: " << cantidad << "\n";
}

void ListaEnteros::pop() {
    if (cabeza == nullptr) {
        cout << "\t[ListaEnteros] Error: La lista de enteros está vacía.\n";
        return;
    }

    cout << "\t[ListaEnteros] pop()  |  eliminado: " << cola->dato << "\n";

    if (cabeza == cola) {
        delete cabeza;
        cabeza = nullptr;
        cola   = nullptr;
    } else {
        Nodo* penultimo = cabeza;
        while (penultimo->siguiente != cola) {
            penultimo = penultimo->siguiente;
        }
        delete cola;
        penultimo->siguiente = nullptr;
        cola = penultimo;
    }

    cantidad--;
}

int ListaEnteros::top() const {
    if (cola == nullptr) {
        cout << "\t[ListaEnteros] Error: La lista de enteros está vacía.\n";
        return 0;
    }
    return cola->dato;
}

int ListaEnteros::size() const {
    return cantidad;
}

bool ListaEnteros::isEmpty() const {
    return cabeza == nullptr;
}

void ListaEnteros::mostrar() const {
    cout << "[ListaEnteros] tope → base: ";

    if (cabeza == nullptr) {
        cout << "(vacía)\n";
        return;
    }

    int* buf = new int[cantidad];
    Nodo* actual = cabeza;
    for (int i = 0; i < cantidad; i++) {
        buf[i] = actual->dato;
        actual = actual->siguiente;
    }

    for (int i = cantidad - 1; i >= 0; i--) {
        cout << buf[i] << " ";
    }
    delete[] buf;

    cout << "\n";
}