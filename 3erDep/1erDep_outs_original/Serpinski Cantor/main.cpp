#include <iostream>
#include "../output_writer.h"
#include "serpinskicantor.cpp"
#include "serpinskicantor.h"

using namespace std;

int main(){
    Serpinski serpinski1;
    Cantor    cantor1;
    int n, d;

    OutputCapture cap;

    cout << "Ingresa Nivel (Serpinski): ";
    cin >> n;
    cout << "Triangulos en nivel " << n << ": " << serpinski1.nElemsLvl(n) << endl;

    cout << "\nIngresa Nivel (Cantor): ";
    cin >> n;
    cout << "Ingresa Dimension (Cantor): ";
    cin >> d;
    cout << "Elementos en nivel " << n << ", dimension " << d << ": "
         << cantor1.nElemsLvl(n, d) << endl;

    writeAllOutputs("SerpinskiCantor", cap.get());
    return 0;
}
