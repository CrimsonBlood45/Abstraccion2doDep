#include "cola.h"
#include <iostream>

using namespace std;

ColaEnteros::ColaEnteros() : frente(0), cantidad(0) {}

bool ColaEnteros::isEmpty() const {
    return cantidad == 0;
}

void ColaEnteros::enqueue(int valor) {
    if (cantidad >= CAPACIDAD_MAX) {
        cout << "\t[ColaEnteros] Error: La cola está llena.\n";
        return;
    }
    int indice = (frente + cantidad) % CAPACIDAD_MAX;
    datos[indice] = valor;
    cantidad++;
    cout << "\t[ColaEnteros] enqueue(" << valor << ")  |  tamaño: " << cantidad << "\n";
}

void ColaEnteros::dequeue() {
    if (isEmpty()) {
        cout << "\t[ColaEnteros] Error: La cola está vacía.\n";
        return;
    }
    cout << "\t[ColaEnteros] dequeue()  |  eliminado: " << datos[frente] << "\n";
    frente = (frente + 1) % CAPACIDAD_MAX;
    cantidad--;
}

int ColaEnteros::front() const {
    if (isEmpty()) {
        cout << "\t[ColaEnteros] Error: La cola está vacía.\n";
        return -1;
    }
    return datos[frente];
}

int ColaEnteros::size() const {
    return cantidad;
}

void ColaEnteros::mostrar() const {
    if (isEmpty()) {
        cout << "[ColaEnteros] (vacía)\n";
        return;
    }
    cout << "[ColaEnteros] frente → final: ";
    for (int i = 0; i < cantidad; i++) {
        cout << datos[(frente + i) % CAPACIDAD_MAX] << " ";
    }
    cout << "\n";
}
