#include <iostream>
#include "../output_writer.h"
#include "dato.h"

using namespace std;

struct Auto1   { double precio; int año; };
struct Persona1{ string nombre, ap, am, genero; int edad; };

int main(int argc, char** argv){
    Auto1    autos[3];
    Persona1 personas[4];

    autos[1].año=2026; autos[1].precio=1000000;
    autos[2].año=2026; autos[2].precio=2000000;

    personas[1]={"Araceli","Martinez","Rodriguez","F",57};
    personas[2]={"Jorge",  "Garcia",  "Saavedra", "M",55};
    personas[3]={"Celeste", "Rodriguez","Saavedra","F",13};

    OutputCapture cap;

    cout << "===== Arreglo de Autos =====" << endl;
    for(int i=1;i<=2;i++)
        cout<<"Auto "<<i<<": Año="<<autos[i].año<<", Precio="<<autos[i].precio<<endl;

    cout << "===== Arreglo de Personas =====" << endl;
    for(int i=1;i<=3;i++)
        cout<<"Persona "<<i<<": "
            <<personas[i].nombre<<" "<<personas[i].ap<<" "<<personas[i].am
            <<", Edad="<<personas[i].edad<<", Genero="<<personas[i].genero<<endl;

    writeAllOutputs("ArregloDatos", cap.get());
    return 0;
}
