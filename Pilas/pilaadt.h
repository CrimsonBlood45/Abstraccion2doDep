#ifndef PILAADT_H
#define PILAADT_H

class PilaADT {
public:
    virtual void push(int valor) = 0;
    virtual void pop() = 0;
    virtual int top() const = 0;
    virtual int size() const = 0;
    virtual bool isEmpty() const = 0;
    virtual void mostrar() const = 0;
};

#endif