#include <iostream>
#include "menupila.h"

using namespace std;

void MenuPila::mostrarMenu() {
    cout << "=== Menú de Operaciones con Pila ===" << std::endl;
    cout << "1. Agregar elemento a la pila (push)" << std::endl;
    cout << "2. Eliminar elemento de la pila (pop)" << std::endl;
    cout << "3. Ver el último elemento de la pila (top)" << std::endl;
    cout << "4. Ver el tamaño de la pila (size)" << std::endl;
    cout << "5. Ver si la pila está vacía (isEmpty)" << std::endl;
    cout << "6. Mostrar elementos de la pila (mostrar)" << std::endl;
    cout << "7. Salir" << std::endl;
}
void MenuPila::ejecutarOpcion(int opt) {
    if((opt == 2 || opt == 3 || opt == 4 || opt == 6) && pila->isEmpty()) {
        cout << "La pila está vacía. Por favor, agregue elementos antes de realizar esta operación." << std::endl;
        return;
    }
    switch (opt) {
        case 1:
            cout << "Opción: Agregar elemento a la pila (push)" << std::endl;
            cout << "Ingrese el número a agregar: ";
            cin >> num;
            pila->push(num);
            break;
        case 2:
            cout << "Opción: Eliminar elemento de la pila (pop)" << std::endl;
            pila->pop();
            break;
        case 3:
            cout << "Opción: Ver el último elemento de la pila (top)" << std::endl;
            cout << "El último elemento de la pila es: " << pila->top() << std::endl;
            break;
        case 4:
            cout << "Opción: Ver el tamaño de la pila (size)" << std::endl;
            cout << "El tamaño de la pila es: " << pila->size() << std::endl;
            break;
        case 5:
            cout << "Opción: Ver si la pila está vacía (isEmpty)" << std::endl;
            cout << "La pila está vacía: " << (pila->isEmpty() ? "Sí" : "No") << std::endl;
            break;
        case 6:
            cout << "Opción: Mostrar elementos de la pila (mostrar)" << std::endl;
            pila->mostrar();
            break;
        case 7:
            cout << "Saliendo del programa..." << std::endl;
            break;
        default:
            cout << "Opción no válida. Por favor, intente nuevamente." << std::endl;
    }
}
bool MenuPila::salirMenu() {
    return opt == 7;
}