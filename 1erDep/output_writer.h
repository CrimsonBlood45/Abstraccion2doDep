#ifndef OUTPUT_WRITER_H
#define OUTPUT_WRITER_H

#include <fstream>
#include <sstream>
#include <string>

// Ruta base del proyecto (carpeta raíz 1erDep)
#define OUTPUT_DIR "../"

// Escribe al archivo out.json en la raíz del proyecto
// Formato: agrega un objeto JSON al array del archivo
inline void writeJSON(const std::string& programa, const std::string& salida) {
    std::string path = std::string(OUTPUT_DIR) + "out.json";
    // Leer contenido actual
    std::ifstream inFile(path);
    std::string content = "";
    if (inFile.is_open()) {
        std::string line;
        while (std::getline(inFile, line)) content += line + "\n";
        inFile.close();
    }

    // Si el archivo tiene un array existente, insertar antes del cierre ]
    std::ofstream outFile;
    if (content.empty() || content.find('[') == std::string::npos) {
        outFile.open(path, std::ios::trunc);
        outFile << "[\n";
    } else {
        // Remover el ] final para agregar nueva entrada
        size_t lastBracket = content.rfind(']');
        if (lastBracket != std::string::npos) {
            content = content.substr(0, lastBracket);
            // Agregar coma si ya hay entradas
            size_t lastBrace = content.rfind('}');
            if (lastBrace != std::string::npos) content += ",\n";
        }
        outFile.open(path, std::ios::trunc);
        outFile << content;
    }

    // Escapar salida para JSON
    std::string escaped;
    for (char c : salida) {
        if (c == '"')  escaped += "\\\"";
        else if (c == '\\') escaped += "\\\\";
        else if (c == '\n') escaped += "\\n";
        else if (c == '\r') escaped += "\\r";
        else if (c == '\t') escaped += "\\t";
        else escaped += c;
    }

    outFile << "  {\n"
            << "    \"programa\": \"" << programa << "\",\n"
            << "    \"salida\": \"" << escaped << "\"\n"
            << "  }\n]\n";
    outFile.close();
}

// Escribe al archivo out.xml en la raíz del proyecto
inline void writeXML(const std::string& programa, const std::string& salida) {
    std::string path = std::string(OUTPUT_DIR) + "out.xml";
    std::ifstream inFile(path);
    std::string content = "";
    if (inFile.is_open()) {
        std::string line;
        while (std::getline(inFile, line)) content += line + "\n";
        inFile.close();
    }

    // Escapar caracteres especiales XML
    std::string escaped;
    for (char c : salida) {
        if      (c == '&')  escaped += "&amp;";
        else if (c == '<')  escaped += "&lt;";
        else if (c == '>')  escaped += "&gt;";
        else if (c == '"')  escaped += "&quot;";
        else if (c == '\'') escaped += "&apos;";
        else escaped += c;
    }

    std::ofstream outFile;
    if (content.empty() || content.find("<programas>") == std::string::npos) {
        outFile.open(path, std::ios::trunc);
        outFile << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<programas>\n";
    } else {
        size_t closeTag = content.rfind("</programas>");
        if (closeTag != std::string::npos) content = content.substr(0, closeTag);
        outFile.open(path, std::ios::trunc);
        outFile << content;
    }

    outFile << "  <entrada>\n"
            << "    <programa>" << programa << "</programa>\n"
            << "    <salida>" << escaped << "</salida>\n"
            << "  </entrada>\n"
            << "</programas>\n";
    outFile.close();
}

// Escribe al archivo out.csv en la raíz del proyecto
inline void writeCSV(const std::string& programa, const std::string& salida) {
    std::string path = std::string(OUTPUT_DIR) + "out.csv";
    bool fileExists = false;
    {
        std::ifstream checkFile(path);
        fileExists = checkFile.is_open() && checkFile.peek() != std::ifstream::traits_type::eof();
    }

    std::ofstream outFile(path, std::ios::app);
    // Escribir encabezado si el archivo es nuevo
    if (!fileExists) outFile << "programa,salida\n";

    // Escapar salida para CSV (envolver en comillas, escapar comillas internas)
    std::string escaped;
    for (char c : salida) {
        if (c == '"') escaped += "\"\"";
        else escaped += c;
    }
    outFile << "\"" << programa << "\",\"" << escaped << "\"\n";
    outFile.close();
}

// Escribe al archivo out.txt en la raíz del proyecto
inline void writeTXT(const std::string& programa, const std::string& salida) {
    std::string path = std::string(OUTPUT_DIR) + "out.txt";
    std::ofstream outFile(path, std::ios::app);
    outFile << "========================================\n"
            << "PROGRAMA: " << programa << "\n"
            << "----------------------------------------\n"
            << salida << "\n"
            << "========================================\n\n";
    outFile.close();
}

// Escribe a los 4 archivos de salida de una sola vez
inline void writeAllOutputs(const std::string& programa, const std::string& salida) {
    writeJSON(programa, salida);
    writeXML(programa, salida);
    writeCSV(programa, salida);
    writeTXT(programa, salida);
}

#endif // OUTPUT_WRITER_H
