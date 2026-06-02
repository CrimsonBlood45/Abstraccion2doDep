#include "pila.h"
#include <iostream>

using namespace std;

PilaEnteros::PilaEnteros() : tope(nullptr), cantidad(0) {}

PilaEnteros::~PilaEnteros() {
    while (tope != nullptr) {
        NodoPila* siguiente = tope->siguiente;
        delete tope;
        tope = siguiente;
    }
}

void PilaEnteros::push(int valor) {
    NodoPila* nuevo = new NodoPila(valor, tope);
    tope = nuevo;
    cantidad++;
    cout << "\t[PilaEnteros] push(" << valor << ")  |  tamaño: " << cantidad << "\n";
}

void PilaEnteros::pop() {
    if (tope == nullptr) {
        cout << "La pila de enteros está vacía.\n";
        return;
    }
    cout << "\t[PilaEnteros] pop()  |  eliminado: " << tope->valor << "\n";
    NodoPila* siguiente = tope->siguiente;
    delete tope;
    tope = siguiente;
    cantidad--;
}

int PilaEnteros::top() const {
    if (tope == nullptr) {
        cout << "La pila de enteros está vacía.\n";
        return 0;
    }
    return tope->valor;
}

int PilaEnteros::size() const {
    return cantidad;
}

bool PilaEnteros::isEmpty() const {
    return tope == nullptr;
}

void PilaEnteros::mostrar() const {
    cout << "\t[PilaEnteros] tope → base: ";
    if (tope == nullptr) {
        cout << "(vacía)\n";
        return;
    }
    NodoPila* actual = tope;
    while (actual != nullptr) {
        cout << actual->valor << " ";
        actual = actual->siguiente;
    }
    cout << "\n";
}
