#ifndef MENU_PILA_H
#define MENU_PILA_H
#include "pilaadt.h"
class MenuPila {
private:
    PilaADT *pila;
public:
    int opt, num;
    MenuPila(PilaADT *pila) : pila(pila) {}
    void mostrarMenu();
    void ejecutarOpcion(int opt);
    bool salirMenu();
};

#endif