#include <iostream>
#include "calculadora.h"
#include "calculadora.cpp"

using namespace std;

int main() {

    CalculadoraNueva calc;

    int a, b, c;

    
    cout << "Ingrese dos numeros para suma: ";
    cin >> a >> b;
    cout << "Suma (2 parametros): " << calc.suma(a,b) << endl;

    cout << "Ingrese tres numeros para suma: ";
    cin >> a >> b >> c;
    cout << "Suma (3 parametros): " << calc.suma(a,b,c) << endl;

    calc.suma(); 

    
    cout << "\nIngrese dos numeros para resta: ";
    cin >> a >> b;
    cout << "Resta (2 parametros): " << calc.resta(a,b) << endl;

    cout << "Ingrese tres numeros para resta: ";
    cin >> a >> b >> c;
    cout << "Resta (3 parametros): " << calc.resta(a,b,c) << endl;

    calc.resta();

    
    cout << "\nIngrese dos numeros para multiplicacion: ";
    cin >> a >> b;
    cout << "Multiplicacion (2 parametros): " << calc.multiplicacion(a,b) << endl;

    cout << "Ingrese tres numeros para multiplicacion: ";
    cin >> a >> b >> c;
    cout << "Multiplicacion (3 parametros): " << calc.multiplicacion(a,b,c) << endl;

    calc.multiplicacion();

    
    cout << "\nIngrese dos numeros para division: ";
    cin >> a >> b;
    cout << "Division (2 parametros): " << calc.division(a,b) << endl;

    cout << "Ingrese tres numeros para division: ";
    cin >> a >> b >> c;
    cout << "Division (3 parametros): " << calc.division(a,b,c) << endl;

    calc.division();

    
    cout << "\nIngrese base y exponente para potencia: ";
    cin >> a >> b;
    cout << "Potencia: " << calc.potencia(a,b) << endl;

    cout << "Ingrese dos numeros para modulo: ";
    cin >> a >> b;
    cout << "Modulo: " << calc.modulo(a,b) << endl;

    return 0;
}