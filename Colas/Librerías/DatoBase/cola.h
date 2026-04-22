#ifndef COLA_H
#define COLA_H

#include <queue>
#include "../../colaadt.h"

class ColaEnteros : public ColaADT {
private:
    std::queue<int> cola;
public:
    void push(int valor) override;
    void pop() override;
    int  front() const override;
    int  size() const override;
    bool isEmpty() const override;
    void mostrar() const override;
};

#endif