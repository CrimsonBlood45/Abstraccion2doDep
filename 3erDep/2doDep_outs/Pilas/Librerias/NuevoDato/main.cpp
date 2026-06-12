#include <iostream>
#include "../../../output_writer.h"
#include "pila.cpp"
#include "../../menupila.cpp"

using namespace std;

int main() {
    OutputCapture cap;

    PilaEnteros pila;
    MenuPila menu(&pila);
    do {
        menu.mostrarMenu();
        cout << "> ";
        cin >> menu.opt;
        menu.ejecutarOpcion(menu.opt);
    } while (!menu.salirMenu());

    writeAllOutputs("Pilas/Librerias/NuevoDato", cap.get());
    return 0;
}
