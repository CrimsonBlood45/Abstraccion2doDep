#ifndef LISTA_H
#define LISTA_H

class Lista {
private:
    int* datos;
    int capacidad;
    int tam;

    void redimensionar();

public:
    Lista(int cap = 5);
    ~Lista();

    void insertar(int valor);
    void eliminar(int valor);
    void mostrar();
};

#endif