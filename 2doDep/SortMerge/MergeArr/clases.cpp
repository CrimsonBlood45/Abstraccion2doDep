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

void Ordenador::mergeEnteros(int arr[], int izq, int mid, int der) {
    int i = izq, j = mid + 1, k = 0;
    int temp[100];
    while (i <= mid && j <= der) {
        if (arr[i] < arr[j]) temp[k++] = arr[i++];
        else                  temp[k++] = arr[j++];
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= der)  temp[k++] = arr[j++];
    for (int x = 0; x < k; x++) arr[izq + x] = temp[x];
}

void Ordenador::mergeSortEnteros(int arr[], int izq, int der) {
    if (izq < der) {
        int mid = (izq + der) / 2;
        mergeSortEnteros(arr, izq, mid);
        mergeSortEnteros(arr, mid + 1, der);
        mergeEnteros(arr, izq, mid, der);
    }
}

void Ordenador::mergeChars(char arr[], int izq, int mid, int der) {
    int i = izq, j = mid + 1, k = 0;
    char temp[100];
    while (i <= mid && j <= der) {
        if (arr[i] < arr[j]) temp[k++] = arr[i++];
        else                  temp[k++] = arr[j++];
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= der)  temp[k++] = arr[j++];
    for (int x = 0; x < k; x++) arr[izq + x] = temp[x];
}

void Ordenador::mergeSortChars(char arr[], int izq, int der) {
    if (izq < der) {
        int mid = (izq + der) / 2;
        mergeSortChars(arr, izq, mid);
        mergeSortChars(arr, mid + 1, der);
        mergeChars(arr, izq, mid, der);
    }
}

void Ordenador::mergePersonas(Persona arr[], int izq, int mid, int der) {
    int i = izq, j = mid + 1, k = 0;
    Persona temp[50];
    while (i <= mid && j <= der) {
        if (arr[i].getEdad() < arr[j].getEdad()) temp[k++] = arr[i++];
        else                                      temp[k++] = arr[j++];
    }
    while (i <= mid) temp[k++] = arr[i++];
    while (j <= der)  temp[k++] = arr[j++];
    for (int x = 0; x < k; x++) arr[izq + x] = temp[x];
}

void Ordenador::mergeSortPersonas(Persona arr[], int izq, int der) {
    if (izq < der) {
        int mid = (izq + der) / 2;
        mergeSortPersonas(arr, izq, mid);
        mergeSortPersonas(arr, mid + 1, der);
        mergePersonas(arr, izq, mid, der);
    }
}
