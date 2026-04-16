#include "lista.h"
#include <iostream>

using namespace std;

void ListaEnteros::push(int valor) {
    lista.push_back(valor); // tope = back()
    cout << "[ListaEnteros] push(" << valor << ")  |  tamaño: " << lista.size() << "\n";
}

void ListaEnteros::pop() {
    if (lista.empty()) {
        cout << "La lista de enteros está vacía." << "\n";
        return;
    }

    cout << "[ListaEnteros] pop()  |  eliminado: " << lista.back() << "\n";
    lista.pop_back();
}

int ListaEnteros::top() const {
    if (lista.empty()) {
        cout << "Error: La lista de enteros está vacía." << endl;
        return 0;
    }
    return lista.back();
}

int ListaEnteros::size() const {
    return static_cast<int>(lista.size());
}

bool ListaEnteros::isEmpty() const {
    return lista.empty();
}

void ListaEnteros::mostrar() const {
    cout << "[ListaEnteros] tope → base: ";

    for (auto it = lista.rbegin(); it != lista.rend(); ++it) {
        cout << *it << " ";
    }

    cout << "\n";
}