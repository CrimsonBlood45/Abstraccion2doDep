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

    
    int particionEnteros(int arr[], int* idx, int inicio, int fin) {
        int pivote = arr[idx[fin]];
        int i = inicio - 1;

        for (int j = inicio; j < fin; j++) {
            if (arr[idx[j]] < pivote) {
                i++;
                int aux = idx[i];
                idx[i] = idx[j];
                idx[j] = aux;
            }
        }

        int aux = idx[i + 1];
        idx[i + 1] = idx[fin];
        idx[fin] = aux;

        return i + 1;
    }

    void quickSortEnteros(int arr[], int* idx, int inicio, int fin) {
        if (inicio < fin) {
            int pi = particionEnteros(arr, idx, inicio, fin);
            quickSortEnteros(arr, idx, inicio, pi - 1);
            quickSortEnteros(arr, idx, pi + 1, fin);
        }
    }

  
    int particionChars(char arr[], int* idx, int inicio, int fin) {
        char pivote = arr[idx[fin]];
        int i = inicio - 1;

        for (int j = inicio; j < fin; j++) {
            if (arr[idx[j]] < pivote) {
                i++;
                int aux = idx[i];
                idx[i] = idx[j];
                idx[j] = aux;
            }
        }

        int aux = idx[i + 1];
        idx[i + 1] = idx[fin];
        idx[fin] = aux;

        return i + 1;
    }

    void quickSortChars(char arr[], int* idx, int inicio, int fin) {
        if (inicio < fin) {
            int pi = particionChars(arr, idx, inicio, fin);
            quickSortChars(arr, idx, inicio, pi - 1);
            quickSortChars(arr, idx, pi + 1, fin);
        }
    }

  
    int particionPersonas(Persona arr[], int* idx, int inicio, int fin) {
        int pivote = arr[idx[fin]].getEdad();
        int i = inicio - 1;

        for (int j = inicio; j < fin; j++) {
            if (arr[idx[j]].getEdad() < pivote) {
                i++;
                int aux = idx[i];
                idx[i] = idx[j];
                idx[j] = aux;
            }
        }

        int aux = idx[i + 1];
        idx[i + 1] = idx[fin];
        idx[fin] = aux;

        return i + 1;
    }

    void quickSortPersonas(Persona arr[], int* idx, int inicio, int fin) {
        if (inicio < fin) {
            int pi = particionPersonas(arr, idx, inicio, fin);
            quickSortPersonas(arr, idx, inicio, pi - 1);
            quickSortPersonas(arr, idx, pi + 1, fin);
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
        idxEnteros[i] = i;
    }

    ord.quickSortEnteros(enteros, idxEnteros, 0, n - 1);

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

    ord.quickSortChars(caracteres, idxChars, 0, m - 1);

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

    ord.quickSortPersonas(personas, idxPersonas, 0, p - 1);

    cout << "\nPersonas ordenadas por edad (indirecto):\n";
    for (int i = 0; i < p; i++) {
        personas[idxPersonas[i]].mostrar();
    }

    
    delete[] idxEnteros;
    delete[] idxChars;
    delete[] idxPersonas;

    return 0;
}

