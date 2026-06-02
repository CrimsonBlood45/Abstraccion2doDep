#include <iostream>
#include "calculadora.h"
#include "calculadora.cpp"

using namespace std;

int main(){

    Calculadora calc;

    int a,b,c;

    // SUMA
    cout<<"Ingrese dos numeros para suma: ";
    cin>>a>>b;
    cout<<"Suma (2 parametros): "<<calc.suma(a,b)<<endl;

    cout<<"Ingrese tres numeros para suma: ";
    cin>>a>>b>>c;
    cout<<"Suma (3 parametros): "<<calc.suma(a,b,c)<<endl;

    calc.suma();

    // RESTA
    cout<<"\nResta (2 parametros): "<<calc.resta(10,3)<<endl;
    cout<<"Resta (3 parametros): "<<calc.resta(10,3,2)<<endl;
    calc.resta();

    // MULTIPLICACION
    cout<<"\nMultiplicacion (2 parametros): "<<calc.multiplicacion(3,4)<<endl;
    cout<<"Multiplicacion (3 parametros): "<<calc.multiplicacion(3,4,2)<<endl;
    calc.multiplicacion();

    // DIVISION
    cout<<"\nDivision (2 parametros): "<<calc.division(10,2)<<endl;
    cout<<"Division (3 parametros): "<<calc.division(20,2,2)<<endl;
    calc.division();

    return 0;
}