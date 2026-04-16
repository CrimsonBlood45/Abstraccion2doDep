#include <iostream>
#include <string>
using namespace std;

class Persona {
private:
    string nombre;
    int edad;

public:
    void leer() {
        cout << "Nombre: ";
        cin >> nombre;
        cout << "Edad: ";
        cin >> edad;
    }

    int getEdad() {
        return edad;
    }

    void mostrar() {
        cout << nombre << " - " << edad << " años" << endl;
    }
};

class Ordenador {
public:

        void burbujaIndirectaEnteros(int arr[], int* idx, int n) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1 - i; j++) {
                if (arr[idx[j]] > arr[idx[j + 1]]) {
                    int aux = idx[j];
                    idx[j] = idx[j + 1];
                    idx[j + 1] = aux;
                }
            }
        }
    }

       void burbujaIndirectaChars(char arr[], int* idx, int n) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1 - i; j++) {
                if (arr[idx[j]] > arr[idx[j + 1]]) {
                    int aux = idx[j];
                    idx[j] = idx[j + 1];
                    idx[j + 1] = aux;
                }
            }
        }
    }

       void burbujaIndirectaPersonas(Persona arr[], int* idx, int n) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1 - i; j++) {
                if (arr[idx[j]].getEdad() > arr[idx[j + 1]].getEdad()) {
                    int aux = idx[j];
                    idx[j] = idx[j + 1];
                    idx[j + 1] = aux;
                }
            }
        }
    }
};

int main() {
    Ordenador ord;

      int n;
    cout << "Cantidad de enteros: ";
    cin >> n;

    int enteros[100];
    int* idxEnteros = new int[n];

    cout << "Ingresa los enteros:\n";
    for (int i = 0; i < n; i++) {
        cin >> enteros[i];
        idxEnteros[i] = i; // inicializar índices
    }

    ord.burbujaIndirectaEnteros(enteros, idxEnteros, n);

    cout << "Enteros ordenados (indirecto):\n";
    for (int i = 0; i < n; i++) {
        cout << enteros[idxEnteros[i]] << " ";
    }
    cout << endl;

  
    int m;
    cout << "\nCantidad de caracteres: ";
    cin >> m;

    char caracteres[100];
    int* idxChars = new int[m];

    cout << "Ingresa los caracteres:\n";
    for (int i = 0; i < m; i++) {
        cin >> caracteres[i];
        idxChars[i] = i;
    }

    ord.burbujaIndirectaChars(caracteres, idxChars, m);

    cout << "Caracteres ordenados (indirecto):\n";
    for (int i = 0; i < m; i++) {
        cout << caracteres[idxChars[i]] << " ";
    }
    cout << endl;

      int p;
    cout << "\nCantidad de personas: ";
    cin >> p;

    Persona personas[50];
    int* idxPersonas = new int[p];

    cout << "Ingresa los datos de las personas:\n";
    for (int i = 0; i < p; i++) {
        cout << "Persona " << i + 1 << endl;
        personas[i].leer();
        idxPersonas[i] = i;
    }

    ord.burbujaIndirectaPersonas(personas, idxPersonas, p);

    cout << "\nPersonas ordenadas por edad (indirecto):\n";
    for (int i = 0; i < p; i++) {
        personas[idxPersonas[i]].mostrar();
    }

       delete[] idxEnteros;
    delete[] idxChars;
    delete[] idxPersonas;

    return 0;
}

