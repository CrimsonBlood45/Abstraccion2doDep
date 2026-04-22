#ifndef COLA_H
#define COLA_H
#include "../../colaadt.h"

class ColaEnteros : public ColaADT {
public:  
  int *arr;
  int final;
  int capacidad;

  ColaEnteros(int cap = 5);
  ~ColaEnteros();

  void redimensionar();
  void push(int valor) override;
  void pop() override;
  int front() const override;
  int size() const override;
  bool isEmpty() const override;
  void mostrar() const override;
};

#endif
