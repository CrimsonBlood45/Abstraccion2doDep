#include <iostream>
#include "../../../output_writer.h"
#include "cola.cpp"
#include "../../menucola.cpp"

using namespace std;

int main() {
    OutputCapture cap;

    ColaEnteros cola;
    MenuCola menu(&cola);
    do {
        menu.mostrarMenu();
        cout << "> ";
        cin >> menu.opt;
        menu.ejecutarOpcion(menu.opt);
    } while (!menu.salirMenu());

    writeAllOutputs("Colas/Punteros/DatoBase", cap.get());
    return 0;
}
