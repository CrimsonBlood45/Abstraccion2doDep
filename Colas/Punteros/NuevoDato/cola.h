#ifndef COLA_H
#define COLA_H

class Cola {
private:
  //Inicia Declaración de Nuevo Tipo de Dato
  struct Datos {
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
  //Termina Declaración de Nuevo Tipo de Dato

  Datos d;

  void redimensionar();

public:
  Cola(int cap = 4);
  ~Cola();

  bool isEmpty();
  void push(int valor);
  void pop();
  int front();
  void mostrar();
};

#endif