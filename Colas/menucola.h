#ifndef MENU_COLA_H
#define MENU_COLA_H
#include "colaadt.h"
class MenuCola {
private:
    ColaADT *cola;
public:
    int opt, num;
    MenuCola(ColaADT *cola) : cola(cola) {}
    void mostrarMenu();
    void ejecutarOpcion(int opt);
};

#endif