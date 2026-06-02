#include <iostream>
#include "../output_writer.h"
#include "dato.h"

using namespace std;

struct Auto1   { double precio; int año; };
struct Persona1{ string nombre, ap, am, genero; int edad; };

int main(int argc, char** argv){
    OutputCapture cap;

    cout << "===== Creacion de Datos =====" << endl;
    cout << "Ingresa el año del auto (struct): ";
    int anio; cin >> anio;
    cout << "Ingresa el precio del auto (struct): ";
    double precio; cin >> precio;

    Auto1 miAutoStruct; miAutoStruct.año=anio; miAutoStruct.precio=precio;

    cout << "Ingresa nombre, apellido paterno, materno, genero (M/F) y edad de la persona: " << endl;
    Persona1 p;
    cin >> p.nombre >> p.ap >> p.am >> p.genero >> p.edad;

    cout << "\n--- Struct Auto    ---" << endl;
    cout << "Año: " << miAutoStruct.año << ", Precio: " << miAutoStruct.precio << endl;
    cout << "--- Struct Persona ---" << endl;
    cout << p.nombre<<" "<<p.ap<<" "<<p.am<<", Genero: "<<p.genero<<", Edad: "<<p.edad << endl;

    Auto miAutoClase; miAutoClase.año=anio; miAutoClase.precio=precio;
    cout << "--- Clase Auto     ---" << endl;
    cout << "Año: " << miAutoClase.año << ", Precio: " << miAutoClase.precio << endl;

    writeAllOutputs("CreacionDato", cap.get());
    return 0;
}
