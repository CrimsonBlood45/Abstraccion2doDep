#include "../include/arbol.h"
#include <iostream>
#include <queue>

void Arbol::agregarArista(const Arista& a) {
    aristas_.push_back(a);
    adj_[a.origen].push_back({a.destino, a.tiempo}); // dirigido (BFS sigue la dirección)
}

void Arbol::construirDesdeRaiz(const std::string& raiz) {
    raiz_ = raiz;
    hijos_.clear();
    alcanzados_.clear();

    std::queue<std::string> cola;
    cola.push(raiz_);
    alcanzados_.insert(raiz_);
    hijos_[raiz_] = {};

    while (!cola.empty()) {
        std::string u = cola.front(); cola.pop();
        if (!adj_.count(u)) continue;
        for (const auto& [v, w] : adj_.at(u)) {
            if (!alcanzados_.count(v)) {
                alcanzados_.insert(v);
                hijos_[u].push_back(v);
                hijos_.emplace(v, std::vector<std::string>{});
                cola.push(v);
            }
        }
    }

    // Registrar nodos no alcanzables para mostrarlos aparte
    for (const auto& n : nodos_) {
        if (!alcanzados_.count(n.etiqueta))
            hijos_.emplace(n.etiqueta, std::vector<std::string>{});
    }
}

void Arbol::mostrarNodo(const std::string& nodo,
                         const std::string& prefijo,
                         bool               esUltimo,
                         int                peso) const {
    std::cout << prefijo
              << (esUltimo ? "└── " : "├── ")
              << "(" << peso << " min)  [" << nodo << "]\n";

    if (!hijos_.count(nodo)) return;
    const auto& h = hijos_.at(nodo);
    const std::string nuevoPrefijo = prefijo + (esUltimo ? "    " : "│   ");

    for (size_t i = 0; i < h.size(); ++i) {
        // Buscar peso de la arista (nodo → h[i]) en adj_
        int w = 0;
        if (adj_.count(nodo)) {
            for (const auto& [v, pw] : adj_.at(nodo))
                if (v == h[i]) { w = pw; break; }
        }
        mostrarNodo(h[i], nuevoPrefijo, i == h.size() - 1, w);
    }
}

void Arbol::mostrar() const {
    std::cout << "\n╔══════════════════════════════════════════╗\n"
              << "║  ÁRBOL  (BFS desde raíz)                 ║\n"
              << "║  Raíz: " << raiz_ << "\n"
              << "╚══════════════════════════════════════════╝\n"
              << "  Nodos alcanzables: " << alcanzados_.size()
              << " / " << nodos_.size() << "\n\n"
              << "  [" << raiz_ << "]\n";

    if (hijos_.count(raiz_)) {
        const auto& h = hijos_.at(raiz_);
        for (size_t i = 0; i < h.size(); ++i) {
            int w = 0;
            if (adj_.count(raiz_)) {
                for (const auto& [v, pw] : adj_.at(raiz_))
                    if (v == h[i]) { w = pw; break; }
            }
            mostrarNodo(h[i], "  ", i == h.size() - 1, w);
        }
    }

    // Nodos no alcanzables desde la raíz
    bool header = true;
    for (const auto& n : nodos_) {
        if (!alcanzados_.count(n.etiqueta)) {
            if (header) {
                std::cout << "\n  Nodos no alcanzables desde la raíz:\n";
                header = false;
            }
            std::cout << "  ⊗  [" << n.etiqueta << "]\n";
        }
    }
    std::cout << "\n";
}
