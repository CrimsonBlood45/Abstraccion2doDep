#ifndef CALCULADORA_H
#define CALCULADORA_H

#include <iostream>
using namespace std;


class Calculadora {

public:

  
    int suma(int a, int b);
    int suma(int a, int b, int c);
    void suma();

   
    int resta(int a, int b);
    int resta(int a, int b, int c);
    void resta();

    
    virtual float multiplicacion(int a, int b);  
    int multiplicacion(int a, int b, int c);
    void multiplicacion();

   
    virtual float division(float a, float b);  
    float division(float a, float b, float c);
    void division();

};


class CalculadoraNueva : public Calculadora {

public:

    float multiplicacion(int a, int b) override;   
    float potencia(int a, int b);                  
    float division(float a, float b) override;   

    int modulo(int a, int b);                    
    void mensaje();

};

#endif