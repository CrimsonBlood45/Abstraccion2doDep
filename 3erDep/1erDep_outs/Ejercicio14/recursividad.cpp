#include "recursividad.h"

Calculadora::Calculadora(){}
Calculadora::~Calculadora(){}

int Calculadora::multiplicacion(int a, int b){

    if(b == 0)
        return 0;

    return a + multiplicacion(a, b-1);
}

int Calculadora::division(int a, int b){

    if(a < b)
        return 0;

    return 1 + division(a-b, b);
}

int Calculadora::potencia(int a, int b){

    if(b == 0)
        return 1;

    return a * potencia(a, b-1);
}

int Calculadora::factorial(int n){

    if(n == 0 || n == 1)
        return 1;

    return n * factorial(n-1);
}

int Calculadora::fibonacci(int n){

    if(n == 0)
        return 0;

    if(n == 1)
        return 1;

    return fibonacci(n-1) + fibonacci(n-2);
}