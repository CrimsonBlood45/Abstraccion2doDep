#include <iostream>
#include "lista.cpp"

using namespace std;

int main() {
    ListaEnteros lista;

    lista.push(10);
    lista.push(20);
    lista.push(30);

    lista.mostrar();

    cout << "top  = " << lista.top() << "\n";
    cout << "size = " << lista.size() << "\n";

    lista.pop();
    lista.mostrar();

    cout << "Nuevo top() = " << lista.top() << "\n";
    return 0;
}