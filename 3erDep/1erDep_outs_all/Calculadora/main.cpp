#include <iostream>
#include "../output_writer.h"
#include "calculadora.h"
#include "calculadora.cpp"

using namespace std;

int main(){
    Calculadora calc;

    OutputCapture cap;

    int a, b, c;

    // SUMA
    cout << "Ingrese dos numeros para suma: ";
    cin >> a >> b;
    cout << "Suma (2 parametros): " << calc.suma(a,b) << endl;

    cout << "Ingrese tres numeros para suma: ";
    cin >> a >> b >> c;
    cout << "Suma (3 parametros): " << calc.suma(a,b,c) << endl;

    cout << "Suma interactiva (ingrese 3 numeros):" << endl;
    calc.suma();

    // RESTA
    cout << "\nResta (2 param, hardcoded 10-3): " << calc.resta(10,3) << endl;
    cout << "Resta (3 param, hardcoded 10-3-2): " << calc.resta(10,3,2) << endl;
    cout << "Resta interactiva (ingrese 2 numeros):" << endl;
    calc.resta();

    // MULTIPLICACION
    cout << "\nMultiplicacion (2 param, hardcoded 3*4): " << calc.multiplicacion(3,4) << endl;
    cout << "Multiplicacion (3 param, hardcoded 3*4*2): " << calc.multiplicacion(3,4,2) << endl;
    cout << "Multiplicacion interactiva (ingrese 2 numeros):" << endl;
    calc.multiplicacion();

    // DIVISION
    cout << "\nDivision (2 param, hardcoded 10/2): " << calc.division(10,2) << endl;
    cout << "Division (3 param, hardcoded 20/2/2): " << calc.division(20,2,2) << endl;
    cout << "Division interactiva (ingrese 2 numeros):" << endl;
    calc.division();

    writeAllOutputs("Calculadora", cap.get());
    return 0;
}
