#include "../include/parser.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>
#include <cctype>

// ── utilidades internas ───────────────────────────────────────────────────────

static std::string leerArchivo(const std::string& ruta) {
    std::ifstream f(ruta);
    if (!f) throw std::runtime_error("No se pudo abrir: " + ruta);
    std::ostringstream ss;
    ss << f.rdbuf();
    return ss.str();
}

// Lee el primer entero que aparece en la cadena (ej. "10 min" → 10)
static int toMinutos(const std::string& s) {
    std::istringstream iss(s);
    int v = 0; iss >> v; return v;
}

// ── helpers JSON ──────────────────────────────────────────────────────────────

// Devuelve el valor string de la primera ocurrencia de "key": "..."  a partir de start
static std::string jsonStr(const std::string& json,
                            const std::string& key,
                            size_t             start = 0) {
    const std::string sk = "\"" + key + "\"";
    size_t p = json.find(sk, start);
    if (p == std::string::npos) return "";

    // Buscar el ':' y luego la comilla de apertura del valor
    p = json.find(':', p + sk.size());
    if (p == std::string::npos) return "";
    p = json.find('"', p);          // comilla de apertura del valor
    if (p == std::string::npos) return "";
    ++p;                             // saltar la comilla

    std::string val;
    while (p < json.size() && json[p] != '"') {
        if (json[p] == '\\' && p + 1 < json.size()) {
            switch (json[p + 1]) {
                case '"' : val += '"';  p += 2; break;
                case '\\': val += '\\'; p += 2; break;
                case 'n' : val += '\n'; p += 2; break;
                default  : val += json[p]; ++p; break;
            }
        } else {
            val += json[p++];
        }
    }
    return val;
}

// Devuelve el valor entero de la primera ocurrencia de "key": N  a partir de start
static int jsonInt(const std::string& json,
                   const std::string& key,
                   size_t             start = 0) {
    const std::string sk = "\"" + key + "\"";
    size_t p = json.find(sk, start);
    if (p == std::string::npos) return 0;
    p = json.find(':', p + sk.size());
    if (p == std::string::npos) return 0;
    ++p;
    while (p < json.size() &&
           (json[p] == ' ' || json[p] == '\t' ||
            json[p] == '\n' || json[p] == '\r')) ++p;
    try { return std::stoi(json.substr(p)); }
    catch (...) { return 0; }
}

// Extrae el contenido completo del array "key": [ ... ]
static std::string jsonSeccion(const std::string& json, const std::string& key) {
    const std::string sk = "\"" + key + "\"";
    size_t p = json.find(sk);
    if (p == std::string::npos) return "";
    p = json.find('[', p + sk.size());
    if (p == std::string::npos) return "";

    int depth = 0;
    for (size_t i = p; i < json.size(); ++i) {
        if      (json[i] == '[') ++depth;
        else if (json[i] == ']') {
            --depth;
            if (depth == 0) return json.substr(p, i - p + 1);
        }
    }
    return "";
}

// Extrae el siguiente objeto { ... } a partir de pos; actualiza pos
static std::string nextObj(const std::string& s, size_t& pos) {
    size_t start = s.find('{', pos);
    if (start == std::string::npos) { pos = std::string::npos; return ""; }

    int depth = 0;
    for (size_t i = start; i < s.size(); ++i) {
        if      (s[i] == '{') ++depth;
        else if (s[i] == '}') {
            --depth;
            if (depth == 0) { pos = i + 1; return s.substr(start, i - start + 1); }
        }
    }
    pos = std::string::npos;
    return "";
}

// ── helpers XML ───────────────────────────────────────────────────────────────

// Extrae el valor de atributo  attr="..."  dentro de un tag
static std::string xmlAttr(const std::string& tag, const std::string& attr) {
    const std::string sk = attr + "=\"";
    size_t p = tag.find(sk);
    if (p == std::string::npos) return "";
    p += sk.size();
    size_t e = tag.find('"', p);
    if (e == std::string::npos) return "";
    return tag.substr(p, e - p);
}

// Devuelve todos los tags que empiecen con <name (self-closing o no)
static std::vector<std::string> xmlTags(const std::string& xml,
                                         const std::string& name) {
    std::vector<std::string> tags;
    const std::string open = "<" + name;
    size_t pos = 0;
    while ((pos = xml.find(open, pos)) != std::string::npos) {
        size_t end = xml.find('>', pos);
        if (end == std::string::npos) break;
        tags.push_back(xml.substr(pos, end - pos + 1));
        pos = end + 1;
    }
    return tags;
}

// ── parsers públicos ──────────────────────────────────────────────────────────

DatosGrafo parsearJSON(const std::string& ruta) {
    const std::string json = leerArchivo(ruta);
    DatosGrafo datos;
    datos.nombre = jsonStr(json, "nombre");

    // Nodos
    const std::string secNodos = jsonSeccion(json, "nodos");
    size_t pos = 0;
    int autoId = 1;
    std::string obj;
    while (!(obj = nextObj(secNodos, pos)).empty()) {
        Nodo n;
        n.id = jsonInt(obj, "id");
        if (n.id == 0) n.id = autoId;
        n.etiqueta = jsonStr(obj, "etiqueta");
        if (!n.etiqueta.empty()) { datos.nodos.push_back(n); ++autoId; }
    }

    // Aristas
    const std::string secAristas = jsonSeccion(json, "aristas");
    pos = 0;
    while (!(obj = nextObj(secAristas, pos)).empty()) {
        Arista a;
        a.origen  = jsonStr(obj, "origen");
        a.destino = jsonStr(obj, "destino");
        a.costo   = jsonStr(obj, "costo");
        a.tiempo  = toMinutos(jsonStr(obj, "tiempo"));
        if (!a.origen.empty() && !a.destino.empty())
            datos.aristas.push_back(a);
    }

    return datos;
}

DatosGrafo parsearXML(const std::string& ruta) {
    const std::string xml = leerArchivo(ruta);
    DatosGrafo datos;

    // Nombre del digrafo (atributo del tag raíz)
    const auto digrafoTags = xmlTags(xml, "digrafo");
    if (!digrafoTags.empty())
        datos.nombre = xmlAttr(digrafoTags[0], "nombre");

    // Nodos
    int autoId = 1;
    for (const auto& tag : xmlTags(xml, "nodo")) {
        Nodo n;
        const std::string sid = xmlAttr(tag, "id");
        n.id       = sid.empty() ? autoId : std::stoi(sid);
        n.etiqueta = xmlAttr(tag, "etiqueta");
        if (!n.etiqueta.empty()) { datos.nodos.push_back(n); ++autoId; }
    }

    // Aristas
    for (const auto& tag : xmlTags(xml, "arista")) {
        Arista a;
        a.origen  = xmlAttr(tag, "origen");
        a.destino = xmlAttr(tag, "destino");
        a.costo   = xmlAttr(tag, "costo");
        a.tiempo  = toMinutos(xmlAttr(tag, "tiempo"));
        if (!a.origen.empty() && !a.destino.empty())
            datos.aristas.push_back(a);
    }

    return datos;
}

DatosGrafo parsearArchivo(const std::string& nombreArchivo) {
    const size_t dot = nombreArchivo.rfind('.');
    if (dot == std::string::npos)
        throw std::runtime_error(
            "El archivo no tiene extension: " + nombreArchivo);

    std::string ext = nombreArchivo.substr(dot + 1);
    std::transform(ext.begin(), ext.end(), ext.begin(),
                   [](unsigned char c){ return std::tolower(c); });

    if (ext == "json") return parsearJSON(nombreArchivo);
    if (ext == "xml")  return parsearXML(nombreArchivo);

    throw std::runtime_error(
        "Extension no soportada: ." + ext + "  (use .json o .xml)");
}
