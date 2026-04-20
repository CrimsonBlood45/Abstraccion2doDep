#ifndef COLA_H
#define COLA_H

#include <queue>

class ColaEnteros {
private:
    std::queue<int> cola;

public:
    void push(int valor);
    void pop();
    int  front() const;
    int  size() const;
    bool isEmpty() const;
    void mostrar() const;
    void pedirNum(int &num) const;
};

#endif