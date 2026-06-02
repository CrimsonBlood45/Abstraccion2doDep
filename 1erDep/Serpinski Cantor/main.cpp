#include <iostream>
#include "serpinskicantor.cpp"
#include "serpinskicantor.h"

using namespace std;

int main(){
    int n, d;
    Serpinski serpinski1;
    Cantor cantor1;

    cout << "Ingresa Nivel (Serpinski): " << endl;
    cin >> n; 
    cout << "Triangulos: " << serpinski1.nElemsLvl(n) << endl;
    cout << "Ingresa Nivel (Cantor): " << endl;
    cin >> n;
    cout << "Ingresa Dimension (Cantor): " << endl;
    cin >> d;
    cout << "Elementos: " << cantor1.nElemsLvl(n, d) << endl;
}