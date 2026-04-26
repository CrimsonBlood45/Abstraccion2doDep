#include "lista.h"
#include <iostream>

using namespace std;

void ListaEnteros::push(int valor) {
    NodoEntero nodo;
    nodo.valor = valor;

    lista.push_back(nodo);
    cout << "\t[ListaEnteros] push(" << valor << ")  |  tamaño: " << lista.size() << "\n";
}

void ListaEnteros::pop() {
    if (lista.empty()) {
        cout << "La lista de enteros está vacía." << "\n";
        return;
    }

    cout << "\t[ListaEnteros] pop()  |  eliminado: " << lista.back().valor << "\n";
    lista.pop_back();
}

int ListaEnteros::top() const {
    if (lista.empty()) {
        cout << "La lista de enteros está vacía." << "\n";
        return 0;
    }
    return lista.back().valor;
}

int ListaEnteros::size() const {
    return static_cast<int>(lista.size());
}

bool ListaEnteros::isEmpty() const {
    return lista.empty();
}

void ListaEnteros::mostrar() const {
    cout << "\t[ListaEnteros] tope → base: ";

    // Recorremos desde el final al inicio para simular "tope → base"
    for (auto it = lista.rbegin(); it != lista.rend(); ++it) {
        cout << it->valor << " ";
    }

    cout << "\n";
}