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
  int front() const;
  bool isEmpty() const;
  void mostrar() const;
  void pedirNum(int &num) const;
};

#endif
