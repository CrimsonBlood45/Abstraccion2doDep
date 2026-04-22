#include <iostream>
#include "cola.h"
using namespace std;

ColaEnteros::ColaEnteros(int cap) {
    arr = new int[cap];
    final = -1;
}

ColaEnteros::~ColaEnteros() {
    delete[] arr;
}

bool ColaEnteros::isEmpty() const {
    return (final == -1);
}

void ColaEnteros::redimensionar() {
    int nuevaCapacidad = capacidad * 2;
    int *nuevoArr = new int[nuevaCapacidad];

    for (int i = 0; i <= final; i++) {
        nuevoArr[i] = arr[i];
    }

    delete[] arr;
    arr = nuevoArr;
    capacidad = nuevaCapacidad;
}

void ColaEnteros::push(int valor) {
    if (final == capacidad - 1) {
        redimensionar();
    }
    arr[++final] = valor;
}

void ColaEnteros::pop() {
    if (isEmpty()) {
        cout << "Cola vacia\n";
        return;
    }

    for (int i = 0; i < final; i++) {
        arr[i] = arr[i + 1];
    }
    final--;
}

int ColaEnteros::front() const {
    if (isEmpty()) {
        cout << "Cola vacia\n";
        return -1;
    }
    return arr[final];
}

int ColaEnteros::size() const {
    return final + 1;
}

void ColaEnteros::mostrar() const {
    if (isEmpty()) {
        cout << "Cola vacia\n";
        return;
    }

    cout << "Cola: ";
    for (int i = 0; i <= final; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}