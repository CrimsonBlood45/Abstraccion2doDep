#ifndef GRAFO_H
#define GRAFO_H

#include "grafoadt.h"

class Grafo : public GrafoADT {
public:
    void agregarArista(const Arista& a) override;
    void mostrar()                const override;
};

#endif // GRAFO_H
