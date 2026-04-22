#include <iostream>
#include "cola.h"
using namespace std;

ColaEnteros::ColaEnteros(int cap) : d(cap) {}

ColaEnteros::~ColaEnteros() {
}

bool ColaEnteros::isEmpty() const {
    return d.estaVacia();
}

void ColaEnteros::redimensionar() {
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

void ColaEnteros::push(int valor) {
    if (d.final == d.capacidad - 1) {
        redimensionar();
    }
    d.arr[++d.final] = valor;
}

void ColaEnteros::pop() {
    if (isEmpty()) {
        cout << "Cola vacia\n";
        return;
    }
    d.frente++;
}

int ColaEnteros::front() const {
    if (isEmpty()) {
        cout << "Cola vacia\n";
        return -1;
    }
    return d.arr[d.frente];
}
int ColaEnteros::size() const {
    return d.tamano();
}

void ColaEnteros::mostrar() const {
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