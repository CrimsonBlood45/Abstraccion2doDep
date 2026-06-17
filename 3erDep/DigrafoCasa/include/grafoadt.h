#ifndef GRAFOADT_H
#define GRAFOADT_H

#include <string>
#include <vector>
#include <map>

struct Nodo {
    int         id;
    std::string etiqueta;
};

struct Arista {
    std::string origen;
    std::string destino;
    std::string costo;
    int         tiempo;   // peso en minutos
};

struct Ruta {
    std::vector<std::string> nodos;
    int  tiempo_total = 0;
    bool existe       = false;
};

class GrafoADT {
protected:
    std::string         nombre_;
    std::vector<Nodo>   nodos_;
    std::vector<Arista> aristas_;
    std::map<std::string, std::vector<std::pair<std::string, int>>> adj_;

public:
    virtual ~GrafoADT() = default;

    virtual void agregarNodo(const Nodo& n);
    virtual void agregarArista(const Arista& a) = 0;
    virtual void mostrar() const = 0;

    // Dijkstra concreto — usa adj_ que cada subclase construye diferente
    Ruta dijkstra(const std::string& origen,
                  const std::string& destino) const;

    void cargar(const std::vector<Nodo>&   nodos,
                const std::vector<Arista>& aristas,
                const std::string&         nombre);

    const std::vector<Nodo>&   getNodos()   const { return nodos_;  }
    const std::vector<Arista>& getAristas() const { return aristas_; }
    const std::string&         getNombre()  const { return nombre_;  }
};

#endif // GRAFOADT_H
