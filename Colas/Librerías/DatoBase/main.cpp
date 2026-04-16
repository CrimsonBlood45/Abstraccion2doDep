#include <iostream>
#include "cola.cpp"

using namespace std;

int main() {
    ColaEnteros cola;

    cola.push(10);
    cola.push(20);
    cola.push(30);
    cola.mostrar();

    cout << "front = " << cola.front() << "\n";
    cout << "size  = " << cola.size()  << "\n";

    cola.pop();
    cola.mostrar();

    cout << "Nuevo front() = " << cola.front() << "\n";

    return 0;
}