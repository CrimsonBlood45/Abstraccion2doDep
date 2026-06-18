#include "../include/grafoadt.h"
#include <queue>
#include <limits>
#include <algorithm>

void GrafoADT::agregarNodo(const Nodo& n) {
    nodos_.push_back(n);
    adj_[n.etiqueta]; // inicializa lista vacía si no existe
}

void GrafoADT::cargar(const std::vector<Nodo>&   nodos,
                       const std::vector<Arista>& aristas,
                       const std::string&         nombre) {
    nodos_.clear();
    aristas_.clear();
    adj_.clear();
    nombre_ = nombre;
    for (const auto& n : nodos)   agregarNodo(n);
    for (const auto& a : aristas) agregarArista(a);
}

Ruta GrafoADT::dijkstra(const std::string& origen,
                          const std::string& destino) const {
    const int INF = std::numeric_limits<int>::max();

    if (!adj_.count(origen) || !adj_.count(destino))
        return {{}, 0, false};

    std::map<std::string, int>         dist;
    std::map<std::string, std::string> prev;

    for (const auto& [k, _] : adj_) dist[k] = INF;
    dist[origen] = 0;

    using Pi = std::pair<int, std::string>;
    std::priority_queue<Pi, std::vector<Pi>, std::greater<Pi>> pq;
    pq.push({0, origen});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (const auto& [v, w] : adj_.at(u)) {
            int alt = dist[u] + w;
            if (alt < dist[v]) {
                dist[v] = alt;
                prev[v] = u;
                pq.push({alt, v});
            }
        }
    }

    if (dist[destino] == INF) return {{}, 0, false};

    Ruta r;
    r.tiempo_total = dist[destino];
    r.existe       = true;

    for (std::string cur = destino; cur != origen; ) {
        r.nodos.push_back(cur);
        if (!prev.count(cur)) { r.existe = false; r.nodos.clear(); return r; }
        cur = prev[cur];
    }
    r.nodos.push_back(origen);
    std::reverse(r.nodos.begin(), r.nodos.end());
    return r;
}

Ruta GrafoADT::encontrarCiclo(const std::string& inicio) const {
    if (!adj_.count(inicio)) return {{}, 0, false};

    Ruta mejor;
    mejor.existe       = false;
    mejor.tiempo_total = std::numeric_limits<int>::max();

    for (const auto& [v, w] : adj_.at(inicio)) {
        if (v == inicio) continue;           // ignorar auto-bucles
        Ruta regreso = dijkstra(v, inicio);
        if (!regreso.existe) continue;

        int total = w + regreso.tiempo_total;
        if (total < mejor.tiempo_total) {
            mejor.tiempo_total = total;
            mejor.existe       = true;
            mejor.nodos.clear();
            mejor.nodos.push_back(inicio);   // primer nodo del ciclo
            for (const auto& n : regreso.nodos)
                mejor.nodos.push_back(n);    // v → ... → inicio (cerrar ciclo)
        }
    }
    return mejor;
}

Ruta GrafoADT::dijkstraInverso(const std::string& origen,
                                 const std::string& destino) const {
    // Construir grafo transpuesto: invertir todas las aristas
    std::map<std::string, std::vector<std::pair<std::string,int>>> rev;
    for (const auto& [k, _] : adj_) rev[k]; // asegurar que todos los nodos existen
    for (const auto& a : aristas_)
        rev[a.destino].push_back({a.origen, a.tiempo});

    const int INF = std::numeric_limits<int>::max();
    if (!rev.count(origen) || !rev.count(destino))
        return {{}, 0, false};

    std::map<std::string, int>         dist;
    std::map<std::string, std::string> prev;

    for (const auto& [k, _] : rev) dist[k] = INF;
    dist[origen] = 0;

    using Pi = std::pair<int, std::string>;
    std::priority_queue<Pi, std::vector<Pi>, std::greater<Pi>> pq;
    pq.push({0, origen});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (const auto& [v, w] : rev.at(u)) {
            int alt = dist[u] + w;
            if (alt < dist[v]) {
                dist[v] = alt;
                prev[v] = u;
                pq.push({alt, v});
            }
        }
    }

    if (dist[destino] == INF) return {{}, 0, false};

    Ruta r;
    r.tiempo_total = dist[destino];
    r.existe       = true;

    for (std::string cur = destino; cur != origen; ) {
        r.nodos.push_back(cur);
        if (!prev.count(cur)) { r.existe = false; r.nodos.clear(); return r; }
        cur = prev[cur];
    }
    r.nodos.push_back(origen);
    std::reverse(r.nodos.begin(), r.nodos.end());
    return r;
}
