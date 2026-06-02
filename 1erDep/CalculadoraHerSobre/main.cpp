#include <iostream>
#include "calculadora.h"
#include "calculadora.cpp"

using namespace std;

int main(){

    CalculadoraNueva calc;
    int a,b;

    
    /*cout<<"Ingrese dos numeros para multiplicacion: ";
    cin>>a>>b;
    cout<<"Multiplicacion (2 parametros, suma sucesiva): "<<calc.multiplicacion(a, b)<<endl;

   
    cout<<"Ingrese base y exponente para potencia: ";
    cin>>a>>b;
    cout<<"Potencia (multiplicaciones sucesivas): "<<calc.potencia(a,b)<<endl;

    
    float x,y;
    cout<<"Ingrese dividendo y divisor: ";
    cin>>x>>y;
    cout<<"Division (restas sucesivas, division entera): "<<calc.division(x,y)<<endl;
    */
    
    cout<<"Ingrese dos numeros para modulo: ";
    cin>>a>>b;
    cout<<"Modulo: "<<calc.modulo(a,b)<<endl;

    
    calc.mensaje();

    return 0;
}