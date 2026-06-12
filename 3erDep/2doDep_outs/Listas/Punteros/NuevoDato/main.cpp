#include <iostream>
#include "../../../output_writer.h"
#include "lista.cpp"
#include "../../menulista.cpp"

using namespace std;

int main() {
    OutputCapture cap;

    ListaEnteros lista;
    MenuLista menu(&lista);
    do {
        menu.mostrarMenu();
        cout << "> ";
        cin >> menu.opt;
        menu.ejecutarOpcion(menu.opt);
    } while (!menu.salirMenu());

    writeAllOutputs("Listas/Punteros/NuevoDato", cap.get());
    return 0;
}
