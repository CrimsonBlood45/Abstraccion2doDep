#include <iostream>
#include "cola.cpp"
#include "../../menucola.cpp"

using namespace std;

int main() {
    ColaEnteros cola;
    MenuCola menu(&cola);
    do {
        menu.mostrarMenu();
        cout << "> ";
        cin >> menu.opt;
        menu.ejecutarOpcion(menu.opt);
    } while (menu.opt != 7);
}