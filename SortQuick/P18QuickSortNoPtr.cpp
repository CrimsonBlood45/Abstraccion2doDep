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

   
    int particionEnteros(int arr[], int inicio, int fin) {
        int pivote = arr[fin];
        int i = inicio - 1;

        for (int j = inicio; j < fin; j++) {
            if (arr[j] < pivote) {
                i++;
                int aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }

        int aux = arr[i + 1];
        arr[i + 1] = arr[fin];
        arr[fin] = aux;

        return i + 1;
    }

    void quickSortEnteros(int arr[], int inicio, int fin) {
        if (inicio < fin) {
            int pi = particionEnteros(arr, inicio, fin);
            quickSortEnteros(arr, inicio, pi - 1);
            quickSortEnteros(arr, pi + 1, fin);
        }
    }

  
    int particionChars(char arr[], int inicio, int fin) {
        char pivote = arr[fin];
        int i = inicio - 1;

        for (int j = inicio; j < fin; j++) {
            if (arr[j] < pivote) {
                i++;
                char aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }

        char aux = arr[i + 1];
        arr[i + 1] = arr[fin];
        arr[fin] = aux;

        return i + 1;
    }

    void quickSortChars(char arr[], int inicio, int fin) {
        if (inicio < fin) {
            int pi = particionChars(arr, inicio, fin);
            quickSortChars(arr, inicio, pi - 1);
            quickSortChars(arr, pi + 1, fin);
        }
    }

  
    int particionPersonas(Persona arr[], int inicio, int fin) {
        int pivote = arr[fin].getEdad();
        int i = inicio - 1;

        for (int j = inicio; j < fin; j++) {
            if (arr[j].getEdad() < pivote) {
                i++;
                Persona aux = arr[i];
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }

        Persona aux = arr[i + 1];
        arr[i + 1] = arr[fin];
        arr[fin] = aux;

        return i + 1;
    }

    void quickSortPersonas(Persona arr[], int inicio, int fin) {
        if (inicio < fin) {
            int pi = particionPersonas(arr, inicio, fin);
            quickSortPersonas(arr, inicio, pi - 1);
            quickSortPersonas(arr, pi + 1, fin);
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

    ord.quickSortEnteros(enteros, 0, n - 1);

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

    ord.quickSortChars(caracteres, 0, m - 1);

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

    ord.quickSortPersonas(personas, 0, p - 1);

    cout << "\nPersonas ordenadas por edad:\n";
    for (int i = 0; i < p; i++) {
        personas[i].mostrar();
    }

    return 0;
}


