#ifndef LISTAADT_H
#define LISTAADT_H

class ListaADT {
public:
    virtual void insertAt(int valor) = 0;
    virtual void removeAt() = 0;
    virtual int get() const = 0;
    virtual int size() const = 0;
    virtual bool isEmpty() const = 0;
    virtual void mostrar() const = 0;
};

#endif