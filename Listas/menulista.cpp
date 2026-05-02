#include <iostream>
#include "menulista.h"

using namespace std;

void MenuLista::mostrarMenu() {
    cout << "=== Menú de Operaciones con Lista ===" << std::endl;
    cout << "1. Agregar elemento a la lista (insertAt)" << std::endl;
    cout << "2. Eliminar elemento de la lista (removeAt)" << std::endl;
    cout << "3. Ver el último elemento de la lista (get)" << std::endl;
    cout << "4. Ver el tamaño de la lista (size)" << std::endl;
    cout << "5. Ver si la lista está vacía (isEmpty)" << std::endl;
    cout << "6. Mostrar elementos de la lista (mostrar)" << std::endl;
    cout << "7. Salir" << std::endl;
}
void MenuLista::ejecutarOpcion(int opt) {
    if((opt == 2 || opt == 3 || opt == 4 || opt == 6) && lista->isEmpty()) {
        cout << "La lista está vacía. Por favor, agregue elementos antes de realizar esta operación." << std::endl;
        return;
    }
    switch (opt) {
        case 1:
            cout << "Opción: Agregar elemento a la lista (insertAt)" << std::endl;
            cout << "Ingrese el número a agregar: ";
            cin >> num;
            lista->insertAt(num);
            break;
        case 2:
            cout << "Opción: Eliminar elemento de la lista (removeAt)" << std::endl;
            lista->removeAt();
            break;
        case 3:
            cout << "Opción: Ver el último elemento de la lista (get)" << std::endl;
            cout << "El último elemento de la lista es: " << lista->get() << std::endl;
            break;
        case 4:
            cout << "Opción: Ver el tamaño de la lista (size)" << std::endl;
            cout << "El tamaño de la lista es: " << lista->size() << std::endl;
            break;
        case 5:
            cout << "Opción: Ver si la lista está vacía (isEmpty)" << std::endl;
            cout << "La lista está vacía: " << (lista->isEmpty() ? "Sí" : "No") << std::endl;
            break;
        case 6:
            cout << "Opción: Mostrar elementos de la lista (mostrar)" << std::endl;
            lista->mostrar();
            break;
        case 7:
            cout << "Saliendo del programa..." << std::endl;
            break;
        default:
            cout << "Opción no válida. Por favor, intente nuevamente." << std::endl;
    }
}
bool MenuLista::salirMenu() {
    return opt == 7;
}