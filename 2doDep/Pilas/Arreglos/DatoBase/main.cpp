#include <iostream>
#include "pila.cpp"
#include "../../menupila.cpp"

using namespace std;

int main() {
    PilaEnteros pila;
    MenuPila menu(&pila);
    do {
        menu.mostrarMenu();
        cout << "> ";
        cin >> menu.opt;
        menu.ejecutarOpcion(menu.opt);
    } while (!menu.salirMenu());
}
