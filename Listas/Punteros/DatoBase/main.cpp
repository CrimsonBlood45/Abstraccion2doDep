#include <iostream>
#include "lista.cpp"

using namespace std;

int main(){
    Lista lista;

    int num;

    cout << "Ingrese un número para agregar a la lista: ";
    cin >> num;
    lista.insertar(num);
    cout << "Ingrese otro número para agregar a la lista: ";
    cin >> num;
    lista.insertar(num);
    cout << "Ingrese otro número para agregar a la lista: ";
    cin >> num;
    lista.insertar(num);
    lista.mostrar();

    return 0;
}