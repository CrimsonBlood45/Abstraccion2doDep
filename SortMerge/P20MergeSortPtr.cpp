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

    void mergeEnteros(int arr[], int* idx, int izq, int mid, int der) {
        int i = izq, j = mid + 1, k = 0;
        int temp[100];

        while (i <= mid && j <= der) {
            if (arr[idx[i]] < arr[idx[j]]) {
                temp[k++] = idx[i++];
            } else {
                temp[k++] = idx[j++];
            }
        }

        while (i <= mid) temp[k++] = idx[i++];
        while (j <= der) temp[k++] = idx[j++];

        for (int x = 0; x < k; x++) {
            idx[izq + x] = temp[x];
        }
    }

    void mergeSortEnteros(int arr[], int* idx, int izq, int der) {
        if (izq < der) {
            int mid = (izq + der) / 2;
            mergeSortEnteros(arr, idx, izq, mid);
            mergeSortEnteros(arr, idx, mid + 1, der);
            mergeEnteros(arr, idx, izq, mid, der);
        }
    }

   
    void mergeChars(char arr[], int* idx, int izq, int mid, int der) {
        int i = izq, j = mid + 1, k = 0;
        int temp[100];

        while (i <= mid && j <= der) {
            if (arr[idx[i]] < arr[idx[j]]) {
                temp[k++] = idx[i++];
            } else {
                temp[k++] = idx[j++];
            }
        }

        while (i <= mid) temp[k++] = idx[i++];
        while (j <= der) temp[k++] = idx[j++];

        for (int x = 0; x < k; x++) {
            idx[izq + x] = temp[x];
        }
    }

    void mergeSortChars(char arr[], int* idx, int izq, int der) {
        if (izq < der) {
            int mid = (izq + der) / 2;
            mergeSortChars(arr, idx, izq, mid);
            mergeSortChars(arr, idx, mid + 1, der);
            mergeChars(arr, idx, izq, mid, der);
        }
    }

   
    void mergePersonas(Persona arr[], int* idx, int izq, int mid, int der) {
        int i = izq, j = mid + 1, k = 0;
        int temp[50];

        while (i <= mid && j <= der) {
            if (arr[idx[i]].getEdad() < arr[idx[j]].getEdad()) {
                temp[k++] = idx[i++];
            } else {
                temp[k++] = idx[j++];
            }
        }

        while (i <= mid) temp[k++] = idx[i++];
        while (j <= der) temp[k++] = idx[j++];

        for (int x = 0; x < k; x++) {
            idx[izq + x] = temp[x];
        }
    }

    void mergeSortPersonas(Persona arr[], int* idx, int izq, int der) {
        if (izq < der) {
            int mid = (izq + der) / 2;
            mergeSortPersonas(arr, idx, izq, mid);
            mergeSortPersonas(arr, idx, mid + 1, der);
            mergePersonas(arr, idx, izq, mid, der);
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

    ord.mergeSortEnteros(enteros, idxEnteros, 0, n - 1);

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

    ord.mergeSortChars(caracteres, idxChars, 0, m - 1);

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

    ord.mergeSortPersonas(personas, idxPersonas, 0, p - 1);

    cout << "\nPersonas ordenadas por edad (indirecto):\n";
    for (int i = 0; i < p; i++) {
        personas[idxPersonas[i]].mostrar();
    }

   
    delete[] idxEnteros;
    delete[] idxChars;
    delete[] idxPersonas;

    return 0;
}


