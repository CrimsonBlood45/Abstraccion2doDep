#include "../include/grafo.h"
#include <iostream>

void Grafo::agregarArista(const Arista& a) {
    aristas_.push_back(a);
    adj_[a.origen].push_back({a.destino, a.tiempo});
    adj_[a.destino].push_back({a.origen,  a.tiempo}); // bidireccional
}

void Grafo::mostrar() const {
    std::cout << "\n+==========================================+\n"
              << "|  GRAFO (No Dirigido): " << nombre_ << "\n"
              << "+==========================================+\n"
              << "  Nodos  : " << nodos_.size() << "\n"
              << "  Aristas: " << aristas_.size()
              << "  (cada una vale en ambas direcciones)\n\n"
              << "  Lista de adyacencia:\n";

    for (const auto& [nodo, vecinos] : adj_) {
        std::cout << "\n  +- " << nodo << "\n";
        if (vecinos.empty()) {
            std::cout << "  |   (sin conexiones)\n";
        } else {
            for (const auto& [v, w] : vecinos)
                std::cout << "  |   <->  " << v << "  [" << w << " min]\n";
        }
    }
    std::cout << "\n";
}
