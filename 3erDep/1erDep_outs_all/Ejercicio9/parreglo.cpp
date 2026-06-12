#include "parreglo.h"
#include <iostream>

using namespace std;

PromedioArreglo::PromedioArreglo(){}

PromedioArreglo::~PromedioArreglo(){}

void PromedioArreglo::leer(){

    for(int i=0; i<5; i++){
        cout << "Numero " << i+1 << ": ";
        cin >> n[i];
    }

}

void PromedioArreglo::calcular(){

    float suma = 0;
    float max = n[0];
    float min = n[0];

    for(int i=0; i<5; i++){

        suma = suma + n[i];

        if(n[i] > max){
            max = n[i];
        }

        if(n[i] < min){
            min = n[i];
        }

    }

    cout << "Suma: " << suma << endl;
    cout << "Promedio: " << suma/5 << endl;
    cout << "Maximo: " << max << endl;
    cout << "Minimo: " << min << endl;

}