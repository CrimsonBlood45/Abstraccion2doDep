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

    
    void mergeEnteros(int arr[], int izq, int mid, int der) {
        int i = izq, j = mid + 1, k = 0;
        int temp[100];

        while (i <= mid && j <= der) {
            if (arr[i] < arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
            }
        }

        while (i <= mid) temp[k++] = arr[i++];
        while (j <= der) temp[k++] = arr[j++];

        for (int x = 0; x < k; x++) {
            arr[izq + x] = temp[x];
        }
    }

    void mergeSortEnteros(int arr[], int izq, int der) {
        if (izq < der) {
            int mid = (izq + der) / 2;
            mergeSortEnteros(arr, izq, mid);
            mergeSortEnteros(arr, mid + 1, der);
            mergeEnteros(arr, izq, mid, der);
        }
    }

  
    void mergeChars(char arr[], int izq, int mid, int der) {
        int i = izq, j = mid + 1, k = 0;
        char temp[100];

        while (i <= mid && j <= der) {
            if (arr[i] < arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
            }
        }

        while (i <= mid) temp[k++] = arr[i++];
        while (j <= der) temp[k++] = arr[j++];

        for (int x = 0; x < k; x++) {
            arr[izq + x] = temp[x];
        }
    }

    void mergeSortChars(char arr[], int izq, int der) {
        if (izq < der) {
            int mid = (izq + der) / 2;
            mergeSortChars(arr, izq, mid);
            mergeSortChars(arr, mid + 1, der);
            mergeChars(arr, izq, mid, der);
        }
    }

 
    void mergePersonas(Persona arr[], int izq, int mid, int der) {
        int i = izq, j = mid + 1, k = 0;
        Persona temp[50];

        while (i <= mid && j <= der) {
            if (arr[i].getEdad() < arr[j].getEdad()) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
            }
        }

        while (i <= mid) temp[k++] = arr[i++];
        while (j <= der) temp[k++] = arr[j++];

        for (int x = 0; x < k; x++) {
            arr[izq + x] = temp[x];
        }
    }

    void mergeSortPersonas(Persona arr[], int izq, int der) {
        if (izq < der) {
            int mid = (izq + der) / 2;
            mergeSortPersonas(arr, izq, mid);
            mergeSortPersonas(arr, mid + 1, der);
            mergePersonas(arr, izq, mid, der);
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

    ord.mergeSortEnteros(enteros, 0, n - 1);

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

    ord.mergeSortChars(caracteres, 0, m - 1);

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

    ord.mergeSortPersonas(personas, 0, p - 1);

    cout << "\nPersonas ordenadas por edad:\n";
    for (int i = 0; i < p; i++) {
        personas[i].mostrar();
    }

    return 0;
}


