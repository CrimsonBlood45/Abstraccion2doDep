#include <cmath>
#include "calculadora.h"

int Calculadora::suma(int a,int b){ return a+b; }
int Calculadora::suma(int a,int b,int c){ return a+b+c; }
void Calculadora::suma(){
    int a,b;
    cout<<"Ingrese dos numeros: ";
    cin>>a>>b;
    cout<<"Resultado: "<<a+b<<endl;
}
int Calculadora::resta(int a,int b){ return a-b; }
int Calculadora::resta(int a,int b,int c){ return a-b-c; }
void Calculadora::resta(){
    int a,b;
    cout<<"Ingrese dos numeros: ";
    cin>>a>>b;
    cout<<"Resultado: "<<a-b<<endl;
}
float Calculadora::multiplicacion(int a,int b){ return a*b; }
int Calculadora::multiplicacion(int a,int b,int c){ return a*b*c; }
void Calculadora::multiplicacion(){
    int a,b;
    cout<<"Ingrese dos numeros: ";
    cin>>a>>b;
    cout<<"Resultado: "<<a*b<<endl;
}
float Calculadora::division(float a,float b){ return a/b; }
float Calculadora::division(float a,float b,float c){ return a/b/c; }
void Calculadora::division(){
    float a,b;
    cout<<"Ingrese dos numeros: ";
    cin>>a>>b;
    cout<<"Resultado: "<<a/b<<endl;
}
float CalculadoraNueva::multiplicacion(int a,int b){
    float resultado=0;
    for(int i=0; i < abs(b); i++){
        resultado += abs(a);
    }
    if(a < 0 ^ b < 0){return -resultado;}
    return resultado;
}
float CalculadoraNueva::potencia(int a,int b){
    float resultado = 1;
    if(b == 0){return 1;}
    for(int i=0; i < abs(b) && b > 0; i++){
        resultado = resultado*a;
    }
    for(int i=0; i < abs(b) && b < 0; i++){
        resultado = resultado*1/a; 
    }
    return resultado;
}
float CalculadoraNueva::division(float a,float b){
    int contador=0;
    int tempa, tempb;
    tempa = abs(a);
    tempb = abs(b);
    while(tempa >= tempb){
        tempa -= tempb;
        contador++;
    }
    if(a < 0 ^ b < 0){return -contador;}
    return contador; 
}
int CalculadoraNueva::modulo(int a,int b){
    int tempa, tempb;
    tempa = abs(a);
    tempb = abs(b);
    while(tempa >= tempb){
        tempa -= tempb;
    }
    if(a < 0 ^ b < 0){return a + b;}
    return a < 0 && b < 0 ? -tempa : tempa;
}
void CalculadoraNueva::mensaje(){
    cout<<"\nEsta es la Calculadora Nueva con sobreescritura"<<endl;
}