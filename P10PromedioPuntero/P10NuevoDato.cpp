#include <iostream>
using namespace std;


struct Arreglo {
    int *datos;
    int n;
};

class Calculos {
private:
    Arreglo a;

public:
    Calculos(int tam) {
        a.n = tam;
        a.datos = new int[a.n];
    }

    void leer() {
        cout << "Ingresa 5 numeros:\n";
        for (int i = 0; i < a.n; i++) {
            cout << "Numero " << i + 1 << ": ";
            cin >> *(a.datos + i); 
        }
    }

    void calcular() {
        int suma = 0;
        int max = *(a.datos);
        int min = *(a.datos);

        for (int i = 0; i < a.n; i++) {
            suma += *(a.datos + i);

            if (*(a.datos + i) > max) {
                max = *(a.datos + i);
            }

            if (*(a.datos + i) < min) {
                min = *(a.datos + i);
            }
        }

        float promedio = (float)suma / a.n;

        cout << "\n--- Resultados ---\n";
        cout << "Suma: " << suma << endl;
        cout << "Promedio: " << promedio << endl;
        cout << "Maximo: " << max << endl;
        cout << "Minimo: " << min << endl;
    }
};

int main() {
    Calculos obj(5);

    obj.leer();
    obj.calcular();

    return 0;
}

