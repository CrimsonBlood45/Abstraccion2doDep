#include <iostream>
#include "../output_writer.h"
#include "calculadora.h"
#include "calculadora.cpp"

using namespace std;

int main() {
    CalculadoraNueva calc;

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
    cout << "\nIngrese dos numeros para resta: ";
    cin >> a >> b;
    cout << "Resta (2 parametros): " << calc.resta(a,b) << endl;

    cout << "Ingrese tres numeros para resta: ";
    cin >> a >> b >> c;
    cout << "Resta (3 parametros): " << calc.resta(a,b,c) << endl;

    cout << "Resta interactiva (ingrese 2 numeros):" << endl;
    calc.resta();

    // MULTIPLICACION
    cout << "\nIngrese dos numeros para multiplicacion: ";
    cin >> a >> b;
    cout << "Multiplicacion (2 parametros): " << calc.multiplicacion(a,b) << endl;

    cout << "Ingrese tres numeros para multiplicacion: ";
    cin >> a >> b >> c;
    cout << "Multiplicacion (3 parametros): " << calc.multiplicacion(a,b,c) << endl;

    cout << "Multiplicacion interactiva (ingrese 2 numeros):" << endl;
    calc.multiplicacion();

    // DIVISION
    cout << "\nIngrese dos numeros para division: ";
    cin >> a >> b;
    cout << "Division (2 parametros): " << calc.division(a,b) << endl;

    cout << "Ingrese tres numeros para division: ";
    cin >> a >> b >> c;
    cout << "Division (3 parametros): " << calc.division(a,b,c) << endl;

    cout << "Division interactiva (ingrese 2 numeros):" << endl;
    calc.division();

    // POTENCIA y MODULO
    cout << "\nIngrese base y exponente para potencia: ";
    cin >> a >> b;
    cout << "Potencia: " << calc.potencia(a,b) << endl;

    cout << "Ingrese dos numeros para modulo: ";
    cin >> a >> b;
    cout << "Modulo: " << calc.modulo(a,b) << endl;

    writeAllOutputs("CalculadoraHerencia", cap.get());
    return 0;
}
