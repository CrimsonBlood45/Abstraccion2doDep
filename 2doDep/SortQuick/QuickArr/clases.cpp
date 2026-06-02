#include <iostream>
#include "clases.h"
using namespace std;

// ── Persona ───────────────────────────────────────────────

void Persona::leer() {
    cout << "Nombre: ";
    cin >> nombre;
    cout << "Edad: ";
    cin >> edad;
}

int Persona::getEdad() {
    return edad;
}

void Persona::mostrar() {
    cout << nombre << " - " << edad << " años" << endl;
}

// ── Ordenador ─────────────────────────────────────────────

int Ordenador::particionEnteros(int arr[], int inicio, int fin) {
    int pivote = arr[fin];
    int i = inicio - 1;
    for (int j = inicio; j < fin; j++) {
        if (arr[j] < pivote) {
            i++;
            int aux = arr[i]; arr[i] = arr[j]; arr[j] = aux;
        }
    }
    int aux = arr[i + 1]; arr[i + 1] = arr[fin]; arr[fin] = aux;
    return i + 1;
}

void Ordenador::quickSortEnteros(int arr[], int inicio, int fin) {
    if (inicio < fin) {
        int pi = particionEnteros(arr, inicio, fin);
        quickSortEnteros(arr, inicio, pi - 1);
        quickSortEnteros(arr, pi + 1, fin);
    }
}

int Ordenador::particionChars(char arr[], int inicio, int fin) {
    char pivote = arr[fin];
    int i = inicio - 1;
    for (int j = inicio; j < fin; j++) {
        if (arr[j] < pivote) {
            i++;
            char aux = arr[i]; arr[i] = arr[j]; arr[j] = aux;
        }
    }
    char aux = arr[i + 1]; arr[i + 1] = arr[fin]; arr[fin] = aux;
    return i + 1;
}

void Ordenador::quickSortChars(char arr[], int inicio, int fin) {
    if (inicio < fin) {
        int pi = particionChars(arr, inicio, fin);
        quickSortChars(arr, inicio, pi - 1);
        quickSortChars(arr, pi + 1, fin);
    }
}

int Ordenador::particionPersonas(Persona arr[], int inicio, int fin) {
    int pivote = arr[fin].getEdad();
    int i = inicio - 1;
    for (int j = inicio; j < fin; j++) {
        if (arr[j].getEdad() < pivote) {
            i++;
            Persona aux = arr[i]; arr[i] = arr[j]; arr[j] = aux;
        }
    }
    Persona aux = arr[i + 1]; arr[i + 1] = arr[fin]; arr[fin] = aux;
    return i + 1;
}

void Ordenador::quickSortPersonas(Persona arr[], int inicio, int fin) {
    if (inicio < fin) {
        int pi = particionPersonas(arr, inicio, fin);
        quickSortPersonas(arr, inicio, pi - 1);
        quickSortPersonas(arr, pi + 1, fin);
    }
}
