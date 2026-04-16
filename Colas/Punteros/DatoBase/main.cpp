#include <iostream>
#include "cola.h"
using namespace std;

int main() {
    Cola c;

    c.push(10);
    c.push(20);
    c.push(30);
    c.push(40);
    c.push(50);
    c.push(60);

    c.mostrar();

    cout << "Frente: " << c.front() << endl;

    c.pop();
    cout << "\nDespues de pop\n";
    c.mostrar();

    return 0;
}