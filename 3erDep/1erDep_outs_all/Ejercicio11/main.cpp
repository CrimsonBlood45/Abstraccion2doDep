#include <iostream>
#include "../output_writer.h"
#include "matrices.h"
#include "matrices.cpp"

using namespace std;

int main() {
    OutputCapture cap;

    Matrices obj;

    obj.leerA();
    obj.leerB();
    obj.multiplicarConstante();
    obj.multiplicarMatrices();

    writeAllOutputs("Ejercicio11", cap.get());
    return 0;
}
