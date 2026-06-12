#ifndef MENU_LISTA_H
#define MENU_LISTA_H
#include "listaadt.h"
class MenuLista {
private:
    ListaADT *lista;
public:
    int opt, num;
    MenuLista(ListaADT *lista) : lista(lista) {}
    void mostrarMenu();
    void ejecutarOpcion(int opt);
    bool salirMenu();
};

#endif