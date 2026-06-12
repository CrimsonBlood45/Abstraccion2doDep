#ifndef COLA_H
#define COLA_H
#include "../../colaadt.h"

#define CAPACIDAD_MAX 100

class ColaEnteros : public ColaADT {
private:
    int datos[CAPACIDAD_MAX];
    int frente;
    int cantidad;

public:
    ColaEnteros();

    void enqueue(int valor) override;
    void dequeue()        override;
    int  front()   const override;
    int  size()    const override;
    bool isEmpty() const override;
    void mostrar() const override;
};

#endif
