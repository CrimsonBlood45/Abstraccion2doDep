#include "promedios.h"
#include <iostream>

using namespace std;

Promedio::Promedio(){}

Promedio::~Promedio(){}

void Promedio::leer(){

    cout<<"Numero 1: "; cin>>n1;
    cout<<"Numero 2: "; cin>>n2;
    cout<<"Numero 3: "; cin>>n3;
    cout<<"Numero 4: "; cin>>n4;
    cout<<"Numero 5: "; cin>>n5;

}

void Promedio::calcular(){

    suma=n1+n2+n3+n4+n5;
    promedio=suma/5;

    max=n1;
    min=n1;

    if(n2>max) max=n2;
    if(n3>max) max=n3;
    if(n4>max) max=n4;
    if(n5>max) max=n5;

    if(n2<min) min=n2;
    if(n3<min) min=n3;
    if(n4<min) min=n4;
    if(n5<min) min=n5;

}

void Promedio::mostrar(){

    cout<<"Suma: "<<suma<<endl;
    cout<<"Promedio: "<<promedio<<endl;
    cout<<"Maximo: "<<max<<endl;
    cout<<"Minimo: "<<min<<endl;

}