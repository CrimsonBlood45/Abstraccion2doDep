#include <iostream>
using namespace std;

class Persona {
public:
    string nombre, ap, am, genero;
    int edad;
};

class Sistema {
private:
    Persona *personas;
    int n;

public:
    Sistema(int tam) {
        n = tam;
        personas = new Persona[n];
    }

    void cargar() {
        (*(personas + 0)).nombre = "Araceli";
        (*(personas + 0)).ap = "Martinez";
        (*(personas + 0)).am = "Rodriguez";
        (*(personas + 0)).edad = 57;
        (*(personas + 0)).genero = "F";

        (*(personas + 1)).nombre = "Jorge";
        (*(personas + 1)).ap = "Garcia";
        (*(personas + 1)).am = "Saavedra";
        (*(personas + 1)).edad = 55;
        (*(personas + 1)).genero = "M";

        (*(personas + 2)).nombre = "Celeste";
        (*(personas + 2)).ap = "Rodriguez";
        (*(personas + 2)).am = "Saavedra";
        (*(personas + 2)).edad = 13;
        (*(personas + 2)).genero = "F";
    }

    void mostrar() {
        for (int i = 0; i < n; i++) {
            cout << "\nPersona " << i + 1 << endl;
            cout << "Nombre: " << (*(personas + i)).nombre << endl;
            cout << "Apellido paterno: " << (*(personas + i)).ap << endl;
            cout << "Apellido materno: " << (*(personas + i)).am << endl;
            cout << "Edad: " << (*(personas + i)).edad << endl;
            cout << "Genero: " << (*(personas + i)).genero << endl;
        }
    }
};

int main() {
    Sistema s(3);

    s.cargar();
    s.mostrar();

    return 0;
}

