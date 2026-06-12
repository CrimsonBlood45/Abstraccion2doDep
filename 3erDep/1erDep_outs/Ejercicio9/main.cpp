#include <iostream>
#include "../output_writer.h"
#include "parreglo.h"
#include "parreglo.cpp"

using namespace std;

int main() {
    OutputCapture cap;

    PromedioArreglo obj;

    obj.leer();
    obj.calcular();

    writeAllOutputs("Ejercicio9", cap.get());
    return 0;
}
