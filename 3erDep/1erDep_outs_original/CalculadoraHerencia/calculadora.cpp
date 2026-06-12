#include "calculadora.h"
#include <iostream>
#include <cmath>

using namespace std;

int CalculadoraNueva::potencia(int a, int b){
    return pow(a,b);
}

int CalculadoraNueva::modulo(int a, int b){
    return a % b;
}
int Calculadora::suma(int a, int b){
    return a + b;
}

int Calculadora::suma(int a, int b, int c){
    return a + b + c;
}

void Calculadora::suma(){
    int a,b,c;

    cout<<"Ingrese el primer numero: ";
    cin>>a;

    cout<<"Ingrese el segundo numero: ";
    cin>>b;

    cout<<"Ingrese el tercer numero: ";
    cin>>c;

    cout<<"Resultado: "<<a+b+c<<endl;
}




int Calculadora::resta(int a, int b){
    return a - b;
}

int Calculadora::resta(int a, int b, int c){
    return a - b - c;
}

void Calculadora::resta(){
    int a,b;

    cout<<"Ingrese dos numeros: ";
    cin>>a>>b;

    cout<<"Resultado: "<<a-b<<endl;
}
int Calculadora::multiplicacion(int a, int b){
    return a * b;
}

int Calculadora::multiplicacion(int a, int b, int c){
    return a * b * c;
}

void Calculadora::multiplicacion(){
    int a,b;

    cout<<"Ingrese dos numeros: ";
    cin>>a>>b;

    cout<<"Resultado: "<<a*b<<endl;
}
float Calculadora::division(float a, float b){
    return a / b;
}

float Calculadora::division(float a, float b, float c){
    return a / b / c;
}

void Calculadora::division(){
    float a,b;

    cout<<"Ingrese dos numeros: ";
    cin>>a>>b;

    cout<<"Resultado: "<<a/b<<endl;
}