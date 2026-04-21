#include <iostream>
#include "lista.cpp"

using namespace std;

int main(){
    ListaEnteros lista;

    int num;

    cout << "Ingrese un número para agregar a la lista: ";
    cin >> num;
    lista.push(num);
    cout << "Ingrese otro número para agregar a la lista: ";
    cin >> num;
    lista.push(num);
    cout << "Ingrese otro número para agregar a la lista: ";
    cin >> num;
    lista.push(num);
    lista.mostrar();

    cout << "top  = " << lista.top()  << "\n";
    cout << "size = " << lista.size() << "\n";

    lista.pop();
    lista.mostrar();

    cout << "Nuevo top() = " << lista.top() << "\n";

    return 0;
}