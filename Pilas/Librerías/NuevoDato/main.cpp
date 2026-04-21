#include <iostream>
#include "pila.cpp"

using namespace std;

int main(){
    PilaEnteros pila;

    int num;

    cout << "Ingrese un número para agregar a la pila: ";
    cin >> num;
    pila.push(num);
    cout << "Ingrese otro número para agregar a la pila: ";
    cin >> num;
    pila.push(num);
    cout << "Ingrese otro número para agregar a la pila: ";
    cin >> num;
    pila.push(num);
    pila.mostrar();

    cout << "top  = " << pila.top()  << "\n";
    cout << "size = " << pila.size() << "\n";

    pila.pop();
    pila.mostrar();

    cout << "Nuevo top() = " << pila.top() << "\n";

    return 0;
}