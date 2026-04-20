#include <iostream>
#include "cola.cpp"

using namespace std;

int main() {
    int num;

    ColaEnteros cola;

    cola.pedirNum(num);
    cola.push(num);
    cola.pedirNum(num);
    cola.push(num);
    cola.pedirNum(num);
    cola.push(num);

    cola.mostrar();

    cout << "front = " << cola.front() << "\n";
    cout << "size  = " << cola.size()  << "\n";

    cola.pop();
    cola.mostrar();

    cout << "Nuevo front() = " << cola.front() << "\n";

    return 0;
}