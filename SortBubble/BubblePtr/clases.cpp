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

void Ordenador::burbujaIndirectaEnteros(int arr[], int* idx, int n) {
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

void Ordenador::burbujaIndirectaChars(char arr[], int* idx, int n) {
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

void Ordenador::burbujaIndirectaPersonas(Persona arr[], int* idx, int n) {
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
