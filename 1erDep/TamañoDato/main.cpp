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
    Auto1 auto1;
    Persona1 persona1;
    Auto carro;
    Persona persona;

    cout << "====================== Tamaños Struct ======================" << endl;
    cout << "Tamaño Struct Auto: " << sizeof(auto1) << endl;
    cout << "Tamaño Precio: " << sizeof(auto1.precio) << endl;
    cout << "Tamaño Año: " << sizeof(auto1.año) << endl;
    cout << "Tamaño Struct Persona: " << sizeof(persona1) << endl;
    cout << "Tamaño Nombre: " << sizeof(persona1.nombre) << endl;
    cout << "Tamaño Apellido Paterno: " << sizeof(persona1.ap) << endl;
    cout << "Tamaño Apellido Materno: " << sizeof(persona1.am) << endl;
    cout << "Tamaño Genero: " << sizeof(persona1.genero) << endl;
    cout << "Tamaño Edad: " << sizeof(persona1.edad) << endl;
    cout << "====================== Tamaños Clases ======================" << endl;
    cout << "Tamaño Clase Auto: " << sizeof(carro) << endl;
    cout << "Tamaño Precio: " << sizeof(carro.precio) << endl;
    cout << "Tamaño Año: " << sizeof(carro.año) << endl;
    cout << "Tamaño Clase Persona: " << sizeof(persona) << endl;
    cout << "Tamaño Nombre: " << sizeof(persona.nombre) << endl;
    cout << "Tamaño Apellido Paterno: " << sizeof(persona.ap) << endl;
    cout << "Tamaño Apellido Materno: " << sizeof(persona.am) << endl;
    cout << "Tamaño Genero: " << sizeof(persona.genero) << endl;
    cout << "Tamaño Edad: " << sizeof(persona.edad) << endl;

}