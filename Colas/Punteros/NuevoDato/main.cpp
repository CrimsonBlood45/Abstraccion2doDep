#include <iostream>
#include "cola.cpp"

using namespace std;

int main() {
    int num;

    Cola cola;

    cola.pedirNum(num);
    cola.push(num);
    cola.pedirNum(num);
    cola.push(num);
    cola.pedirNum(num);
    cola.push(num);

    cola.mostrar();

    cout << "front = " << cola.front() << "\n";

    cola.pop();
    cola.mostrar();

    cout << "Nuevo front() = " << cola.front() << "\n";

    return 0;
}