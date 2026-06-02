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
    cout << "Ingresa los enteros:\n";
    for (int i = 0; i < n; i++) cin >> enteros[i];
    ord.quickSortEnteros(enteros, 0, n - 1);
    cout << "Enteros ordenados:\n";
    for (int i = 0; i < n; i++) cout << enteros[i] << " ";
    cout << endl;

    // ── Caracteres ────────────────────────────────────────
    int m;
    cout << "\nCantidad de caracteres: ";
    cin >> m;
    char caracteres[100];
    cout << "Ingresa los caracteres:\n";
    for (int i = 0; i < m; i++) cin >> caracteres[i];
    ord.quickSortChars(caracteres, 0, m - 1);
    cout << "Caracteres ordenados:\n";
    for (int i = 0; i < m; i++) cout << caracteres[i] << " ";
    cout << endl;

    // ── Personas ──────────────────────────────────────────
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
    for (int i = 0; i < p; i++) personas[i].mostrar();

    return 0;
}
