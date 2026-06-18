#include "../include/digrafo.h"
#include <iostream>

void Digrafo::agregarArista(const Arista& a) {
    aristas_.push_back(a);
    adj_[a.origen].push_back({a.destino, a.tiempo}); // un solo sentido
}

void Digrafo::mostrar() const {
    std::cout << "\n╔══════════════════════════════════════════╗\n"
              << "║  DIGRAFO (Dirigido): " << nombre_ << "\n"
              << "╚══════════════════════════════════════════╝\n"
              << "  Nodos: " << nodos_.size()
              << "  |  Arcos: " << aristas_.size() << "\n\n"
              << "  Lista de adyacencia:\n";

    for (const auto& [nodo, vecinos] : adj_) {
        std::cout << "\n  ┌─ " << nodo << "\n";
        if (vecinos.empty()) {
            std::cout << "  │   (sin salidas)\n";
        } else {
            for (const auto& [v, w] : vecinos)
                std::cout << "  │   →  " << v << "  [" << w << " min]\n";
        }
    }
    std::cout << "\n";
}
