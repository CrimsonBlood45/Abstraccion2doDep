#include "cola.h"
#include <iostream>

using namespace std;

ColaEnteros::ColaEnteros() {}

bool ColaEnteros::isEmpty() const {
    return d.estaVacia();
}

void ColaEnteros::enqueue(int valor) {
    if (d.cantidad >= CAPACIDAD_MAX) {
        cout << "\t[ColaEnteros] Error: La cola está llena.\n";
        return;
    }
    int indice = (d.frente + d.cantidad) % CAPACIDAD_MAX;
    d.arr[indice] = valor;
    d.cantidad++;
    cout << "\t[ColaEnteros] enqueue(" << valor << ")  |  tamaño: " << d.cantidad << "\n";
}

void ColaEnteros::dequeue() {
    if (isEmpty()) {
        cout << "\t[ColaEnteros] Error: La cola está vacía.\n";
        return;
    }
    cout << "\t[ColaEnteros] dequeue()  |  eliminado: " << d.arr[d.frente] << "\n";
    d.frente = (d.frente + 1) % CAPACIDAD_MAX;
    d.cantidad--;
}

int ColaEnteros::front() const {
    if (isEmpty()) {
        cout << "\t[ColaEnteros] Error: La cola está vacía.\n";
        return -1;
    }
    return d.arr[d.frente];
}

int ColaEnteros::size() const {
    return d.tamano();
}

void ColaEnteros::mostrar() const {
    if (isEmpty()) {
        cout << "[ColaEnteros] (vacía)\n";
        return;
    }
    cout << "[ColaEnteros] frente → final: ";
    for (int i = 0; i < d.cantidad; i++) {
        cout << d.arr[(d.frente + i) % CAPACIDAD_MAX] << " ";
    }
    cout << "\n";
}
