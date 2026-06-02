#ifndef CALCULADORA_H
#define CALCULADORA_H

class Calculadora{

public:

    
    int suma(int a, int b);
    int suma(int a, int b, int c);
    void suma();

    
    int resta(int a, int b);
    int resta(int a, int b, int c);
    void resta();

    
    int multiplicacion(int a, int b);
    int multiplicacion(int a, int b, int c);
    void multiplicacion();

    
    float division(float a, float b);
    float division(float a, float b, float c);
    void division();
};

#endif