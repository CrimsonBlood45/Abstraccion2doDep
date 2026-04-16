#ifndef COLA_H
#define COLA_H

class Cola {
public:  
  int *arr;
  int final;
  int capacidad;

  Cola(int cap = 5);
  ~Cola();

  void redimensionar();
  void push(int valor);
  void pop();
  int front();
  bool isEmpty();
  void mostrar();
};

#endif
