#include <iostream>
#include "pila.cpp"

using namespace std;

int main(){
    PilaEnteros pila;

    pila.push(10);
    pila.push(20);
    pila.push(30);
    pila.mostrar();

    cout << "top  = " << pila.top()  << "\n";
    cout << "size = " << pila.size() << "\n";

    pila.pop();
    pila.mostrar();

    cout << "Nuevo top() = " << pila.top() << "\n";

    return 0;
}