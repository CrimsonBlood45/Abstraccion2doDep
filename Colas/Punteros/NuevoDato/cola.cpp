#include <iostream>
#include "cola.h"
using namespace std;

Cola::Cola(int cap) : d(cap) {}

Cola::~Cola() {
}

bool Cola::isEmpty() {
    return d.estaVacia();
}

void Cola::redimensionar() {
    int nuevaCapacidad = d.capacidad * 2;
    int* nuevoArr = new int[nuevaCapacidad];

    int j = 0;
    for (int i = d.frente; i <= d.final; i++) {
        nuevoArr[j++] = d.arr[i];
    }

    delete[] d.arr;
    d.arr = nuevoArr;
    d.final = d.tamano() - 1;
    d.frente = 0;
    d.capacidad = nuevaCapacidad;
}

void Cola::push(int valor) {
    if (d.final == d.capacidad - 1) {
        redimensionar();
    }
    d.arr[++d.final] = valor;
}

void Cola::pop() {
    if (isEmpty()) {
        cout << "Cola vacia\n";
        return;
    }
    d.frente++;
}

int Cola::front() {
    if (isEmpty()) {
        cout << "Cola vacia\n";
        return -1;
    }
    return d.arr[d.frente];
}

void Cola::mostrar() {
    if (isEmpty()) {
        cout << "Cola vacia\n";
        return;
    }
    cout << "Cola: ";
    for (int i = d.frente; i <= d.final; i++) {
        cout << d.arr[i] << " ";
    }
    cout << endl;
}