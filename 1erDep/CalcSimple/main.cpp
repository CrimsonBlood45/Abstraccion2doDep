#include <iostream>
#include "calculadora.h"
#include "calculadora.cpp"

using namespace std;

int main(){

    Calculadora c;

    float a,b;

    cout<<"Numero 1: ";
    cin>>a;

    cout<<"Numero 2: ";
    cin>>b;

    cout<<"Suma: "<<c.suma(a,b)<<endl;
    cout<<"Resta: "<<c.resta(a,b)<<endl;
    cout<<"Multiplicacion: "<<c.multiplicacion(a,b)<<endl;
    cout<<"Division: "<<c.division(a,b)<<endl;

    return 0;
}