#include <iostream>
using namespace std;

class Persona {
public:
    string nombre, ap, am, genero;
    int edad;
};

struct Grupo {
    Persona *personas;
    int n;
};

class Sistema {
private:
    Grupo g;

public:
    Sistema(int tam) {
        g.n = tam;
        g.personas = new Persona[g.n];
    }

    void cargar() {
        (*(g.personas + 0)).nombre = "Luis";
        (*(g.personas + 0)).ap = "Hernandez";
        (*(g.personas + 0)).am = "Lopez";
        (*(g.personas + 0)).edad = 30;
        (*(g.personas + 0)).genero = "M";

        (*(g.personas + 1)).nombre = "Ana";
        (*(g.personas + 1)).ap = "Gomez";
        (*(g.personas + 1)).am = "Perez";
        (*(g.personas + 1)).edad = 25;
        (*(g.personas + 1)).genero = "F";

        (*(g.personas + 2)).nombre = "Carlos";
        (*(g.personas + 2)).ap = "Ramirez";
        (*(g.personas + 2)).am = "Diaz";
        (*(g.personas + 2)).edad = 40;
        (*(g.personas + 2)).genero = "M";
    }

    void mostrar() {
        for (int i = 0; i < g.n; i++) {
            cout << "\nPersona " << i + 1 << endl;
            cout << "Nombre: " << (*(g.personas + i)).nombre << endl;
            cout << "Apellido paterno: " << (*(g.personas + i)).ap << endl;
            cout << "Apellido materno: " << (*(g.personas + i)).am << endl;
            cout << "Edad: " << (*(g.personas + i)).edad << endl;
            cout << "Genero: " << (*(g.personas + i)).genero << endl;
        }
    }
};

int main() {
    Sistema s(3);

    s.cargar();
    s.mostrar();

    return 0;
}








