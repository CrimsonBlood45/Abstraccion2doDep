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
                  << "|  0. Salir                             |\n"
                  << "+---------------------------------------+\n";
        op = leerOpcion(0, 4);

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

                // Dijkstra sobre el digrafo (respeta la dirección de las aristas)
                Digrafo dg;
                dg.cargar(datos.nodos, datos.aristas, datos.nombre);
                const Ruta ruta = dg.dijkstra(origen, destino);

                std::cout << "\n  Origen : " << origen  << "\n"
                          << "  Destino: " << destino << "\n";

                if (!ruta.existe) {
                    std::cout << "  No existe ruta entre estos nodos.\n";
                } else {
                    std::cout << "  Tiempo total: " << ruta.tiempo_total << " min\n"
                              << "  Ruta: ";
                    for (size_t i = 0; i < ruta.nodos.size(); ++i) {
                        if (i) std::cout << "  ->  ";
                        std::cout << ruta.nodos[i];
                    }
                    std::cout << "\n";
                }
                break;
            }
        }
    } while (op != 0);

    std::cout << "\n  Hasta pronto.\n\n";
    return 0;
}
