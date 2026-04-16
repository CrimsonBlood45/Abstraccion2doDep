#include <iostream>
using namespace std;


class Datos {
protected:
    int *numeros;
    int n;

public:
    Datos(int tam) {
        n = tam;
        numeros = new int[n]; 
    }

    void pedirDatos() {
        cout << "Ingresa 5 numeros:\n";
        for (int i = 0; i < n; i++) {
            cout << "Numero " << i + 1 << ": ";
            cin >> *(numeros + i); 
        }
    }
};


class Operaciones : public Datos {
public:
    Operaciones(int tam) : Datos(tam) {}

    void mostrarResultados() {
        int suma = 0;
        int max, min;

        max = min = *numeros;

        for (int i = 0; i < n; i++) {
            suma += *(numeros + i);

            if (*(numeros + i) > max) {
                max = *(numeros + i);
            }

            if (*(numeros + i) < min) {
                min = *(numeros + i);
            }
        }

        float promedio = (float)suma / n;

        cout << "\n--- Resultados ---\n";
        cout << "Suma: " << suma << endl;
        cout << "Promedio: " << promedio << endl;
        cout << "Maximo: " << max << endl;
        cout << "Minimo: " << min << endl;
    }
};

int main() {
    Operaciones obj(5);

    obj.pedirDatos();
    obj.mostrarResultados();

    return 0;
}

