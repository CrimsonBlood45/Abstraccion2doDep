#include <iostream>
#include "../output_writer.h"
#include "promedios.h"
#include "promedio.cpp"

using namespace std;

int main() {
    OutputCapture cap;

    Promedio obj;

    obj.leer();
    obj.calcular();
    obj.mostrar();

    writeAllOutputs("Ejercicio8", cap.get());
    return 0;
}
