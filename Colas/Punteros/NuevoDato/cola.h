#ifndef COLA_H
#define COLA_H
#include "../../colaadt.h"
class Datos{
public:
  int* arr;
  int frente;
  int final;
  int capacidad;

  Datos(int cap = 4)
      : arr(new int[cap]), frente(0), final(-1), capacidad(cap) {}

  ~Datos() {
      delete[] arr;
  }
  int tamano() const {
      return final - frente + 1;
  }
  bool estaVacia() const {
      return frente > final;
  }
};
class ColaEnteros : public ColaADT {
private:
  void redimensionar();
public:
  Datos d;
  ColaEnteros(int cap = 4);
  ~ColaEnteros();

  void push(int valor) override;
  void pop() override;
  int front() const override;
  int size() const override;
  bool isEmpty() const override;
  void mostrar() const override;
};

#endif