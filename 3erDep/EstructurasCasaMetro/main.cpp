#include <iostream>
#include <string>
#include <limits>
#include "src/grafoadt.cpp"
#include "src/grafo.cpp"
#include "src/digrafo.cpp"
#include "src/arbol.cpp"
#include "src/parser.cpp"

// ── helpers de UI ─────────────────────────────────────────────────────────────

static void listarNodos(const std::vector<Nodo>& nodos) {
    for (size_t i = 0; i < nodos.size(); ++i)
        std::cout << "    " << i + 1 << ". " << nodos[i].etiqueta << "\n";
}

static int leerOpcion(int min, int max) {
    int op;
    while (true) {
        std::cout << "  Opcion: ";
        if (std::cin >> op && op >= min && op <= max) {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return op;
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "  Ingrese un numero entre " << min << " y " << max << ".\n";
    }
}

// ── main ──────────────────────────────────────────────────────────────────────

int main() {
    std::cout << "\n+==========================================+\n"
              << "|   Grafos, Digrafos y Arboles - Dijkstra  |\n"
              << "+==========================================+\n\n";

    // ─── 1. Cargar archivo ────────────────────────────────────────────────────
    DatosGrafo datos;
    while (true) {
        std::cout << "Ingrese nombre del archivo (.json o .xml): ";
        std::string archivo;
        std::cin >> archivo;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        try {
            datos = parsearArchivo(archivo);
            std::cout << "\n  Cargado: \"" << datos.nombre << "\"\n"
                      << "  " << datos.nodos.size()   << " nodos  |  "
                      <<         datos.aristas.size() << " aristas\n";
            break;
        } catch (const std::exception& e) {
            std::cerr << "  Error: " << e.what() << "\n"
                      << "  Intente de nuevo.\n\n";
        }
    }

    // ─── 2. Menú principal ────────────────────────────────────────────────────
    int op;
    do {
        std::cout << "\n+---------------------------------------+\n"
                  << "|           MENU PRINCIPAL              |\n"
                  << "+---------------------------------------+\n"
                  << "|  1. Visualizar como Grafo             |\n"
                  << "|  2. Visualizar como Digrafo           |\n"
                  << "|  3. Visualizar como Arbol             |\n"
                  << "|  4. Ruta mas corta (Dijkstra)         |\n"
                  << "|  5. Encontrar ciclo (Loop)            |\n"
                  << "|  0. Salir                             |\n"
                  << "+---------------------------------------+\n";
        op = leerOpcion(0, 5);

        switch (op) {

            case 1: {
                Grafo g;
                g.cargar(datos.nodos, datos.aristas, datos.nombre);
                g.mostrar();
                break;
            }

            case 2: {
                Digrafo d;
                d.cargar(datos.nodos, datos.aristas, datos.nombre);
                d.mostrar();
                break;
            }

            case 3: {
                std::cout << "\n  Nodos disponibles:\n";
                listarNodos(datos.nodos);
                std::cout << "  Seleccione la raiz del arbol: ";
                const int r = leerOpcion(1, (int)datos.nodos.size());
                const std::string raiz = datos.nodos[r - 1].etiqueta;

                Arbol a;
                a.cargar(datos.nodos, datos.aristas, datos.nombre);
                a.construirDesdeRaiz(raiz);
                a.mostrar();
                break;
            }

            case 4: {
                std::cout << "\n  Nodos disponibles:\n";
                listarNodos(datos.nodos);

                std::cout << "  Seleccione origen : ";
                const int si = leerOpcion(1, (int)datos.nodos.size());
                std::cout << "  Seleccione destino: ";
                const int di = leerOpcion(1, (int)datos.nodos.size());

                const std::string origen  = datos.nodos[si - 1].etiqueta;
                const std::string destino = datos.nodos[di - 1].etiqueta;

                Digrafo dg;
                dg.cargar(datos.nodos, datos.aristas, datos.nombre);

                std::cout << "\n  Origen : " << origen  << "\n"
                          << "  Destino: " << destino << "\n";

                Ruta ruta = dg.dijkstra(origen, destino);
                bool inverso = false;

                if (!ruta.existe) {
                    ruta    = dg.dijkstraInverso(origen, destino);
                    inverso = ruta.existe;
                }

                if (!ruta.existe) {
                    std::cout << "  No existe ruta entre estos nodos.\n";
                } else {
                    if (inverso)
                    std::cout << "  Tiempo total: " << ruta.tiempo_total << " min\n"
                              << "  Ruta: ";
                    const std::string flecha = inverso ? "  <-  " : "  ->  ";
                    for (size_t i = 0; i < ruta.nodos.size(); ++i) {
                        if (i) std::cout << flecha;
                        std::cout << ruta.nodos[i];
                    }
                    std::cout << "\n";
                }
                break;
            }

            case 5: {
                std::cout << "\n  Estructura:\n"
                          << "    1. Grafo (no dirigido)\n"
                          << "    2. Digrafo (dirigido)\n";
                const int tipo = leerOpcion(1, 2);

                std::cout << "\n  Nodos disponibles:\n";
                listarNodos(datos.nodos);
                std::cout << "  Seleccione nodo inicial del ciclo: ";
                const int ni = leerOpcion(1, (int)datos.nodos.size());
                const std::string inicio = datos.nodos[ni - 1].etiqueta;

                // Construir estructura, obtener ciclo y copia del adj antes de que
                // el objeto local sea destruido al salir del bloque if/else
                Ruta ciclo;
                std::map<std::string, std::vector<std::pair<std::string,int>>> adj;
                std::string encabezado;

                if (tipo == 1) {
                    Grafo g;
                    g.cargar(datos.nodos, datos.aristas, datos.nombre);
                    ciclo      = g.encontrarCiclo(inicio);
                    adj        = g.getAdj();
                    encabezado = "|  CICLO - Grafo: " + datos.nombre;
                } else {
                    Digrafo d;
                    d.cargar(datos.nodos, datos.aristas, datos.nombre);
                    ciclo      = d.encontrarCiclo(inicio);
                    adj        = d.getAdj();
                    encabezado = "|  CICLO - Digrafo: " + datos.nombre;
                }

                std::cout << "\n+==========================================+\n"
                          << encabezado << "\n"
                          << "+==========================================+\n";

                if (!ciclo.existe) {
                    std::cout << "  No existe ciclo desde: " << inicio << "\n\n";
                    break;
                }

                std::cout << "  Inicio: " << inicio
                          << "  |  Tiempo total: " << ciclo.tiempo_total << " min\n\n";

                // Visualización vertical del loop
                const auto& cn = ciclo.nodos;
                for (size_t i = 0; i < cn.size(); ++i) {
                    if (i == 0) {
                        std::cout << "  .-> [" << cn[i] << "]\n";
                    } else if (i == cn.size() - 1) {
                        std::cout << "  |   [" << cn[i] << "] <-- regresa al inicio\n"
                                  << "  |\n"
                                  << "  +--(ciclo cerrado)\n";
                        break;
                    } else {
                        std::cout << "  |   [" << cn[i] << "]\n";
                    }

                    if (i + 1 < cn.size()) {
                        int w = 0;
                        if (adj.count(cn[i]))
                            for (const auto& [v, pw] : adj.at(cn[i]))
                                if (v == cn[i + 1]) { w = pw; break; }
                        std::cout << "  |        | (" << w << " min)\n"
                                  << "  |        v\n";
                    }
                }
                std::cout << "\n";
                break;
            }
        }
    } while (op != 0);

    std::cout << "\n  Hasta pronto.\n\n";
    return 0;
}
