#ifndef RECURSIVIDAD_H
#define RECURSIVIDAD_H

class Calculadora{

public:

    Calculadora();
    ~Calculadora();

    int multiplicacion(int a, int b);
    int division(int a, int b);
    int potencia(int a, int b);

    int factorial(int n);
    int fibonacci(int n);

};

#endif