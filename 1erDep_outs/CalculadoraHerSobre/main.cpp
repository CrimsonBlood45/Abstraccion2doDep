#include <iostream>
#include "../output_writer.h"
#include "calculadora.h"
#include "calculadora.cpp"

using namespace std;

int main(){
    CalculadoraNueva calc;
    int a, b;
    float x, y;

    OutputCapture cap;

    cout << "Ingrese dos numeros para multiplicacion (suma sucesiva): ";
    cin >> a >> b;
    cout << "Multiplicacion: " << calc.multiplicacion(a, b) << endl;

    cout << "Ingrese base y exponente para potencia (multiplicaciones sucesivas): ";
    cin >> a >> b;
    cout << "Potencia: " << calc.potencia(a, b) << endl;

    cout << "Ingrese dividendo y divisor para division (restas sucesivas, entera): ";
    cin >> x >> y;
    cout << "Division: " << calc.division(x, y) << endl;

    cout << "Ingrese dos numeros para modulo: ";
    cin >> a >> b;
    cout << "Modulo: " << calc.modulo(a, b) << endl;

    calc.mensaje();

    writeAllOutputs("CalculadoraHerSobre", cap.get());
    return 0;
}
