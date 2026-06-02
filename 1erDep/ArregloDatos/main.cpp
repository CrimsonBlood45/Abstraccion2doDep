#include <iostream>
#include "dato.h"

using namespace std;

struct Auto1{
    double precio;
    int año;
};
struct Persona1{
    string nombre, ap, am, genero;
    int edad;
};

int main(int argc, char** argv){
    Auto1 autos[2];
    Persona1 personas[3];

    autos[1].año = 2026;
    autos[1].precio = 1000000;
    autos[2].año = 2026;
    autos[2].precio = 2000000;

    personas[1].nombre = "Araceli";
    personas[1].am = "Rodriguez";
    personas[1].ap = "Martinez";
    personas[1].edad = 57;
    personas[1].genero = "F";
    personas[2].nombre = "Jorge";
    personas[2].am = "Saavedra";
    personas[2].ap = "Garcia";
    personas[2].edad = 55;
    personas[2].genero = "M";
    personas[3].nombre = "Celeste";
    personas[3].am = "Saavedra";
    personas[3].ap = "Rodriguez";
    personas[3].edad = 13;
    personas[3].genero = "F";
}