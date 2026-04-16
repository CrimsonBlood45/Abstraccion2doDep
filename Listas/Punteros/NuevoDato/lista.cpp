#include "lista.h"

Lista::Lista(int cap) {
    bloque.capacidad = cap;
    bloque.tam = 0;
    bloque.elementos = new Elemento[bloque.capacidad];

    for (int i = 0; i < bloque.capacidad; i++) {
        bloque.elementos[i].ocupado = false;
        bloque.elementos[i].valor = 0;
    }
}

Lista::~Lista() {
    delete[] bloque.elementos;
}

void Lista::redimensionar() {
    bloque.capacidad *= 2;
    Elemento* nuevo = new Elemento[bloque.capacidad];

    for (int i = 0; i < bloque.tam; i++) {
        nuevo[i] = bloque.elementos[i];
    }
    for (int i = bloque.tam; i < bloque.capacidad; i++) {
        nuevo[i].valor = 0;
        nuevo[i].ocupado = false;
    }

    delete[] bloque.elementos;
    bloque.elementos = nuevo;
}

void Lista::insertar(int valor) {
    if (bloque.tam == bloque.capacidad) {
        redimensionar();
    }
    bloque.elementos[bloque.tam].valor = valor;
    bloque.elementos[bloque.tam].ocupado = true;
    bloque.tam++;
    cout << "Insertado: " << valor << endl;
}

void Lista::eliminar(int valor) {
    for (int i = 0; i < bloque.tam; i++) {
        if (bloque.elementos[i].ocupado && bloque.elementos[i].valor == valor) {
            // Desplazar elementos hacia la izquierda
            for (int j = i; j < bloque.tam - 1; j++) {
                bloque.elementos[j] = bloque.elementos[j + 1];
            }
            bloque.elementos[bloque.tam - 1].valor = 0;
            bloque.elementos[bloque.tam - 1].ocupado = false;
            bloque.tam--;
            cout << "Eliminado: " << valor << endl;
            return;
        }
    }
    cout << "Valor " << valor << " no encontrado." << endl;
}

void Lista::mostrar() {
    cout << "Lista: [";
    for (int i = 0; i < bloque.tam; i++) {
        if (bloque.elementos[i].ocupado) {
            cout << bloque.elementos[i].valor;
            if (i < bloque.tam - 1) cout << ", ";
        }
    }
    cout << "]" << endl;
}