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

int Ordenador::particionEnteros(int arr[], int* idx, int inicio, int fin) {
    int pivote = arr[idx[fin]];
    int i = inicio - 1;
    for (int j = inicio; j < fin; j++) {
        if (arr[idx[j]] < pivote) {
            i++;
            int aux = idx[i]; idx[i] = idx[j]; idx[j] = aux;
        }
    }
    int aux = idx[i + 1]; idx[i + 1] = idx[fin]; idx[fin] = aux;
    return i + 1;
}

void Ordenador::quickSortEnteros(int arr[], int* idx, int inicio, int fin) {
    if (inicio < fin) {
        int pi = particionEnteros(arr, idx, inicio, fin);
        quickSortEnteros(arr, idx, inicio, pi - 1);
        quickSortEnteros(arr, idx, pi + 1, fin);
    }
}

int Ordenador::particionChars(char arr[], int* idx, int inicio, int fin) {
    char pivote = arr[idx[fin]];
    int i = inicio - 1;
    for (int j = inicio; j < fin; j++) {
        if (arr[idx[j]] < pivote) {
            i++;
            int aux = idx[i]; idx[i] = idx[j]; idx[j] = aux;
        }
    }
    int aux = idx[i + 1]; idx[i + 1] = idx[fin]; idx[fin] = aux;
    return i + 1;
}

void Ordenador::quickSortChars(char arr[], int* idx, int inicio, int fin) {
    if (inicio < fin) {
        int pi = particionChars(arr, idx, inicio, fin);
        quickSortChars(arr, idx, inicio, pi - 1);
        quickSortChars(arr, idx, pi + 1, fin);
    }
}

int Ordenador::particionPersonas(Persona arr[], int* idx, int inicio, int fin) {
    int pivote = arr[idx[fin]].getEdad();
    int i = inicio - 1;
    for (int j = inicio; j < fin; j++) {
        if (arr[idx[j]].getEdad() < pivote) {
            i++;
            int aux = idx[i]; idx[i] = idx[j]; idx[j] = aux;
        }
    }
    int aux = idx[i + 1]; idx[i + 1] = idx[fin]; idx[fin] = aux;
    return i + 1;
}

void Ordenador::quickSortPersonas(Persona arr[], int* idx, int inicio, int fin) {
    if (inicio < fin) {
        int pi = particionPersonas(arr, idx, inicio, fin);
        quickSortPersonas(arr, idx, inicio, pi - 1);
        quickSortPersonas(arr, idx, pi + 1, fin);
    }
}
