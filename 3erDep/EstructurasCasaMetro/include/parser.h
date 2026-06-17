#ifndef PARSER_H
#define PARSER_H

#include "grafoadt.h"
#include <string>

struct DatosGrafo {
    std::string         nombre;
    std::vector<Nodo>   nodos;
    std::vector<Arista> aristas;
};

// Detecta la extensión y delega a parsearJSON o parsearXML
DatosGrafo parsearArchivo(const std::string& nombreArchivo);
DatosGrafo parsearJSON(const std::string& ruta);
DatosGrafo parsearXML(const std::string& ruta);

#endif // PARSER_H
