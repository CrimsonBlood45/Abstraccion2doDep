#ifndef COLA_H
#define COLA_H
#include "../../colaadt.h"

#define CAPACIDAD_MAX 100

class Datos {
public:
    int arr[CAPACIDAD_MAX];
    int frente;
    int cantidad;

    Datos() : frente(0), cantidad(0) {}

    int tamano() const {
        return cantidad;
    }
    bool estaVacia() const {
        return cantidad == 0;
    }
};

class ColaEnteros : public ColaADT {
public:
    Datos d;

    ColaEnteros();

    void enqueue(int valor) override;
    void dequeue()        override;
    int  front()   const override;
    int  size()    const override;
    bool isEmpty() const override;
    void mostrar() const override;
};

#endif
