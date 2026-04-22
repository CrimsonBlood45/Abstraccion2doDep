#ifndef COLAADT_H
#define COLAADT_H

class ColaADT {
public:
    virtual void push(int valor) = 0;
    virtual void pop() = 0;
    virtual int front() const = 0;
    virtual int size() const = 0;
    virtual bool isEmpty() const = 0;
    virtual void mostrar() const = 0;
};

#endif