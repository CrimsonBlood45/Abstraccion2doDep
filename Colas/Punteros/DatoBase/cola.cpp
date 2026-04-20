#include <iostream>
#include "cola.h"
using namespace std;

Cola::Cola(int cap) {
    arr = new int[cap];
    final = -1;
}

Cola::~Cola() {
    delete[] arr;
}

bool Cola::isEmpty() const {
    return (final == -1);
}

void Cola::redimensionar() {
    int nuevaCapacidad = capacidad * 2;
    int *nuevoArr = new int[nuevaCapacidad];

    for (int i = 0; i <= final; i++) {
        nuevoArr[i] = arr[i];
    }

    delete[] arr;
    arr = nuevoArr;
    capacidad = nuevaCapacidad;
}

void Cola::push(int valor) {
    if (final == capacidad - 1) {
        redimensionar();
    }
    arr[++final] = valor;
}

void Cola::pop() {
    if (isEmpty()) {
        cout << "Cola vacia\n";
        return;
    }

    for (int i = 0; i < final; i++) {
        arr[i] = arr[i + 1];
    }
    final--;
}

int Cola::front() const {
    if (isEmpty()) {
        cout << "Cola vacia\n";
        return -1;
    }
    return arr[final];
}

void Cola::mostrar() const {
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
void Cola::pedirNum(int &num) const {
    cout << "Ingrese un número entero: ";
    cin >> num;
}