#include "calculadora.h"
#include <iostream>

using namespace std;

float Calculadora::suma(float a, float b){
    return a + b;
}

float Calculadora::resta(float a, float b){
    return a - b;
}

float Calculadora::multiplicacion(float a, float b){
    return a * b;
}

float Calculadora::division(float a, float b){

    if(b==0){
        cout<<"No se puede dividir entre 0"<<endl;
        return 0;
    }

    return a/b;
}