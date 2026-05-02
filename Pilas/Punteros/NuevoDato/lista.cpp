#include "lista.h"
#include <iostream>

using namespace std;

ListaEnteros::ListaEnteros() : tope(nullptr), cantidad(0) {}

ListaEnteros::~ListaEnteros() {
    while (tope != nullptr) {
        NodoEntero* siguiente = tope->siguiente;
        delete tope;
        tope = siguiente;
    }
}

void ListaEnteros::push(int valor) {
    NodoEntero* nuevo = new NodoEntero(valor, tope);
    tope = nuevo;
    cantidad++;
    cout << "\t[ListaEnteros] push(" << valor << ")  |  tamaño: " << cantidad << "\n";
}

void ListaEnteros::pop() {
    if (tope == nullptr) {
        cout << "La lista de enteros está vacía.\n";
        return;
    }
    cout << "\t[ListaEnteros] pop()  |  eliminado: " << tope->valor << "\n";
    NodoEntero* siguiente = tope->siguiente;
    delete tope;
    tope = siguiente;
    cantidad--;
}

int ListaEnteros::top() const {
    if (tope == nullptr) {
        cout << "La lista de enteros está vacía.\n";
        return 0;
    }
    return tope->valor;
}

int ListaEnteros::size() const {
    return cantidad;
}

bool ListaEnteros::isEmpty() const {
    return tope == nullptr;
}

void ListaEnteros::mostrar() const {
    cout << "\t[ListaEnteros] tope → base: ";
    if (tope == nullptr) {
        cout << "(vacía)\n";
        return;
    }
    NodoEntero* actual = tope;
    while (actual != nullptr) {
        cout << actual->valor << " ";
        actual = actual->siguiente;
    }
    cout << "\n";
}
