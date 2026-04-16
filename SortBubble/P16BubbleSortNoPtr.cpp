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

    string getNombre() {
        return nombre;
    }

    void mostrar() {
        cout << nombre << " - " << edad << " años" << endl;
    }
};


class Ordenador {
public:

    
    void burbujaEnteros(int arr[], int n) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1 - i; j++) {
                if (arr[j] > arr[j + 1]) {
                    int aux = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = aux;
                }
            }
        }
    }

 
    void burbujaChars(char arr[], int n) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1 - i; j++) {
                if (arr[j] > arr[j + 1]) {
                    char aux = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = aux;
                }
            }
        }
    }

   
    void burbujaPersonas(Persona arr[], int n) {
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1 - i; j++) {
                if (arr[j].getEdad() > arr[j + 1].getEdad()) {
                    Persona aux = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = aux;
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

    cout << "Ingresa los enteros:\n";
    for (int i = 0; i < n; i++) {
        cin >> enteros[i];
    }

    ord.burbujaEnteros(enteros, n);

    cout << "Enteros ordenados:\n";
    for (int i = 0; i < n; i++) {
        cout << enteros[i] << " ";
    }
    cout << endl;

  
    int m;
    cout << "\nCantidad de caracteres: ";
    cin >> m;

    char caracteres[100];

    cout << "Ingresa los caracteres:\n";
    for (int i = 0; i < m; i++) {
        cin >> caracteres[i];
    }

    ord.burbujaChars(caracteres, m);

    cout << "Caracteres ordenados:\n";
    for (int i = 0; i < m; i++) {
        cout << caracteres[i] << " ";
    }
    cout << endl;

   
    int p;
    cout << "\nCantidad de personas: ";
    cin >> p;

    Persona personas[50];

    cout << "Ingresa los datos de las personas:\n";
    for (int i = 0; i < p; i++) {
        cout << "Persona " << i + 1 << endl;
        personas[i].leer();
    }

    ord.burbujaPersonas(personas, p);

    cout << "\nPersonas ordenadas por edad:\n";
    for (int i = 0; i < p; i++) {
        personas[i].mostrar();
    }

    return 0;
}



