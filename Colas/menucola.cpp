#include <iostream>
#include "menucola.h"

using namespace std;

void MenuCola::mostrarMenu() {
    cout << "=== Menú de Operaciones con Cola ===" << std::endl;
    cout << "1. Agregar elemento a la cola (push)" << std::endl;
    cout << "2. Eliminar elemento de la cola (pop)" << std::endl;
    cout << "3. Ver el frente de la cola (front)" << std::endl;
    cout << "4. Ver el tamaño de la cola (size)" << std::endl;
    cout << "5. Ver si la cola está vacía (isEmpty)" << std::endl;
    cout << "6. Mostrar elementos de la cola (mostrar)" << std::endl;
    cout << "7. Salir" << std::endl;
}
void MenuCola::ejecutarOpcion(int opt) {
    switch (opt) {
        case 1:
            cout << "Opción: Agregar elemento a la cola (push)" << std::endl;
            cout << "Ingrese el número a agregar: ";
            cin >> num;
            cola->push(num);
            break;
        case 2:
            cout << "Opción: Eliminar elemento de la cola (pop)" << std::endl;
            cola->pop();
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