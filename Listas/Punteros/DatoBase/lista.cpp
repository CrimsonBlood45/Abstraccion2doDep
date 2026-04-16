#include <iostream>
#include "lista.h"

using namespace std;

Lista::Lista(int cap) {
    capacidad = cap;
    tam = 0;
    datos = new int[capacidad];
}

Lista::~Lista() {
    delete[] datos;
}

void Lista::redimensionar() {
    capacidad *= 2;
    int* nuevo = new int[capacidad];

    for (int i = 0; i < tam; i++) {
        nuevo[i] = datos[i];
    }

    delete[] datos;
    datos = nuevo;
}

void Lista::insertar(int valor) {
    if (tam == capacidad) {
        redimensionar();
    }
    datos[tam++] = valor;
}

void Lista::eliminar(int valor) {
    int pos = -1;

    for (int i = 0; i < tam; i++) {
        if (datos[i] == valor) {
            pos = i;
            break;
        }
    }

    if (pos != -1) {
        for (int i = pos; i < tam - 1; i++) {
            datos[i] = datos[i + 1];
        }
        tam--;
        cout << "Elemento eliminado\n";
    } else {
        cout << "Elemento no encontrado\n";
    }
}

void Lista::mostrar() {
    cout << "Lista: ";
    for (int i = 0; i < tam; i++) {
        cout << datos[i] << " ";
    }
    cout << endl;
}