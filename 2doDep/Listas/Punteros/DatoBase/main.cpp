#include <iostream>
#include "lista.cpp"
#include "../../menulista.cpp"

using namespace std;

int main() {
    ListaEnteros lista;
    MenuLista menu(&lista);
    do {
        menu.mostrarMenu();
        cout << "> ";
        cin >> menu.opt;
        menu.ejecutarOpcion(menu.opt);
    } while (!menu.salirMenu());
}