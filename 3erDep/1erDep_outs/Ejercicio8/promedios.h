#ifndef PROMEDIO_H
#define PROMEDIO_H

class Promedio{

private:
    float n1,n2,n3,n4,n5;
    float suma, promedio, max, min;

public:

    Promedio();
    ~Promedio();

    void leer();
    void calcular();
    void mostrar();

};

#endif