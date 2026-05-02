#include <iostream>
#include "menucola.h"

using namespace std;

void MenuCola::mostrarMenu() {
    cout << "=== Menú de Operaciones con Cola ===" << std::endl;
    cout << "1. Agregar elemento a la cola (enqueue)" << std::endl;
    cout << "2. Eliminar elemento de la cola (dequeue)" << std::endl;
    cout << "3. Ver el frente de la cola (front)" << std::endl;
    cout << "4. Ver el tamaño de la cola (size)" << std::endl;
    cout << "5. Ver si la cola está vacía (isEmpty)" << std::endl;
    cout << "6. Mostrar elementos de la cola (mostrar)" << std::endl;
    cout << "7. Salir" << std::endl;
}
void MenuCola::ejecutarOpcion(int opt) {
    if((opt == 2 || opt == 3 || opt == 4 || opt == 6) && cola->isEmpty()) {
        cout << "La cola está vacía. Por favor, agregue elementos antes de realizar esta operación." << std::endl;
        return;
    }
    switch (opt) {
        case 1:
            cout << "Opción: Agregar elemento a la cola (enqueue)" << std::endl;
            cout << "Ingrese el número a agregar: ";
            cin >> num;
            cola->enqueue(num);
            break;
        case 2:
            cout << "Opción: Eliminar elemento de la cola (dequeue)" << std::endl;
            cola->dequeue();
            break;
        case 3:
            cout << "Opción: Ver el frente de la cola (front)" << std::endl;
            cout << "El frente de la cola es: " << cola->front() << std::endl;
            break;
        case 4:
            cout << "Opción: Ver el tamaño de la cola (size)" << std::endl;
            cout << "El tamaño de la cola es: " << cola->size() << std::endl;
            break;
        case 5:
            cout << "Opción: Ver si la cola está vacía (isEmpty)" << std::endl;
            cout << "La cola está vacía: " << (cola->isEmpty() ? "Sí" : "No") << std::endl;
            break;
        case 6:
            cout << "Opción: Mostrar elementos de la cola (mostrar)" << std::endl;
            cola->mostrar();
            break;
        case 7:
            cout << "Saliendo del programa..." << std::endl;
            break;
        default:
            cout << "Opción no válida. Por favor, intente nuevamente." << std::endl;
    }
}
bool MenuCola::salirMenu() {
    return opt == 7;
}