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

void Ordenador::mergeEnteros(int arr[], int* idx, int izq, int mid, int der) {
    int i = izq, j = mid + 1, k = 0;
    int temp[100];
    while (i <= mid && j <= der) {
        if (arr[idx[i]] < arr[idx[j]]) temp[k++] = idx[i++];
        else                            temp[k++] = idx[j++];
    }
    while (i <= mid) temp[k++] = idx[i++];
    while (j <= der)  temp[k++] = idx[j++];
    for (int x = 0; x < k; x++) idx[izq + x] = temp[x];
}

void Ordenador::mergeSortEnteros(int arr[], int* idx, int izq, int der) {
    if (izq < der) {
        int mid = (izq + der) / 2;
        mergeSortEnteros(arr, idx, izq, mid);
        mergeSortEnteros(arr, idx, mid + 1, der);
        mergeEnteros(arr, idx, izq, mid, der);
    }
}

void Ordenador::mergeChars(char arr[], int* idx, int izq, int mid, int der) {
    int i = izq, j = mid + 1, k = 0;
    int temp[100];
    while (i <= mid && j <= der) {
        if (arr[idx[i]] < arr[idx[j]]) temp[k++] = idx[i++];
        else                            temp[k++] = idx[j++];
    }
    while (i <= mid) temp[k++] = idx[i++];
    while (j <= der)  temp[k++] = idx[j++];
    for (int x = 0; x < k; x++) idx[izq + x] = temp[x];
}

void Ordenador::mergeSortChars(char arr[], int* idx, int izq, int der) {
    if (izq < der) {
        int mid = (izq + der) / 2;
        mergeSortChars(arr, idx, izq, mid);
        mergeSortChars(arr, idx, mid + 1, der);
        mergeChars(arr, idx, izq, mid, der);
    }
}

void Ordenador::mergePersonas(Persona arr[], int* idx, int izq, int mid, int der) {
    int i = izq, j = mid + 1, k = 0;
    int temp[50];
    while (i <= mid && j <= der) {
        if (arr[idx[i]].getEdad() < arr[idx[j]].getEdad()) temp[k++] = idx[i++];
        else                                                temp[k++] = idx[j++];
    }
    while (i <= mid) temp[k++] = idx[i++];
    while (j <= der)  temp[k++] = idx[j++];
    for (int x = 0; x < k; x++) idx[izq + x] = temp[x];
}

void Ordenador::mergeSortPersonas(Persona arr[], int* idx, int izq, int der) {
    if (izq < der) {
        int mid = (izq + der) / 2;
        mergeSortPersonas(arr, idx, izq, mid);
        mergeSortPersonas(arr, idx, mid + 1, der);
        mergePersonas(arr, idx, izq, mid, der);
    }
}
