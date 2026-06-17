#ifndef DIGRAFO_H
#define DIGRAFO_H

#include "grafoadt.h"

class Digrafo : public GrafoADT {
public:
    void agregarArista(const Arista& a) override;
    void mostrar()                const override;
};

#endif // DIGRAFO_H
