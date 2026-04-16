#include <iostream>
#include "lista.cpp"
using namespace std;

int main() {
    Lista lista;
    lista.insertar(10);
    lista.insertar(20);
    lista.insertar(30);
    lista.insertar(40);
    lista.insertar(50);
    lista.insertar(60);
    lista.mostrar();
    lista.eliminar(30);
    lista.mostrar();
    lista.eliminar(100);
    return 0;
}