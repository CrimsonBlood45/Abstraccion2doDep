#include <iostream>
#include "clases.h"
using namespace std;

int main() {
    Ordenador ord;

    // ── Enteros ───────────────────────────────────────────
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
    for (int i = 0; i < n; i++) cout << enteros[idxEnteros[i]] << " ";
    cout << endl;

    // ── Caracteres ────────────────────────────────────────
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
    for (int i = 0; i < m; i++) cout << caracteres[idxChars[i]] << " ";
    cout << endl;

    // ── Personas ──────────────────────────────────────────
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
    for (int i = 0; i < p; i++) personas[idxPersonas[i]].mostrar();

    delete[] idxEnteros;
    delete[] idxChars;
    delete[] idxPersonas;
    return 0;
}
