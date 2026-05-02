#include "lista.h"
#include <iostream>

using namespace std;

ListaEnteros::ListaEnteros(int cap)
    : cantidad(0), capacidad(cap) {
    datos = new int[capacidad];
}

ListaEnteros::~ListaEnteros() {
    delete[] datos;
}

void ListaEnteros::redimensionar() {
    int nuevaCapacidad = capacidad * 2;
    int* nuevo = new int[nuevaCapacidad];
    for (int i = 0; i < cantidad; i++) {
        nuevo[i] = datos[i];
    }
    delete[] datos;
    datos = nuevo;
    capacidad = nuevaCapacidad;
}

void ListaEnteros::push(int valor) {
    if (cantidad == capacidad) {
        redimensionar();
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
