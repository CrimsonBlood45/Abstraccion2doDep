#ifndef ARBOL_H
#define ARBOL_H

#include "grafoadt.h"
#include <set>

class Arbol : public GrafoADT {
public:
    void agregarArista(const Arista& a) override;
    void mostrar()                const override;

    // Construye la estructura de árbol con BFS desde una raíz dada
    void construirDesdeRaiz(const std::string& raiz);

private:
    std::string                                     raiz_;
    std::map<std::string, std::vector<std::string>> hijos_;
    std::set<std::string>                           alcanzados_;

    void mostrarNodo(const std::string& nodo,
                     const std::string& prefijo,
                     bool               esUltimo,
                     int                peso) const;
};

#endif // ARBOL_H
