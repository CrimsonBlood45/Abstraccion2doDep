#include <iostream>
#include "../output_writer.h"
#include "recursividad.h"
#include "recursividad.cpp"

using namespace std;

int main() {
    Calculadora c;

    int a, b, n;

    // Read inputs before starting capture (cin prompts are part of output too)
    OutputCapture cap;

    cout << "Numero 1: "; cin >> a;
    cout << "Numero 2: "; cin >> b;

    cout << "Multiplicacion: " << c.multiplicacion(a, b) << endl;
    cout << "Division: "       << c.division(a, b)       << endl;
    cout << "Potencia: "       << c.potencia(a, b)       << endl;

    cout << "\nNumero para factorial: "; cin >> n;
    cout << "Factorial: " << c.factorial(n) << endl;

    cout << "\nCuantos numeros de Fibonacci quieres: "; cin >> n;
    cout << "Serie Fibonacci: ";
    for (int i = 1; i < n; i++) {
        cout << c.fibonacci(i) << " ";
    }
    cout << endl;

    writeAllOutputs("Ejercicio14", cap.get());
    return 0;
}
