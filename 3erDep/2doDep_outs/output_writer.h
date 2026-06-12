#ifndef OUTPUT_WRITER_H
#define OUTPUT_WRITER_H

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

// ─────────────────────────────────────────────
//  TeeBuffer: duplica cada write a dos streambuf
//  (terminal + ostringstream de captura)
// ─────────────────────────────────────────────
class TeeBuffer : public std::streambuf {
public:
    TeeBuffer(std::streambuf* terminal, std::streambuf* capture)
        : terminal_(terminal), capture_(capture) {}

protected:
    int overflow(int c) override {
        if (c == EOF) return EOF;
        if (terminal_->sputc(c) == EOF) return EOF;
        if (capture_->sputc(c) == EOF) return EOF;
        return c;
    }
    std::streamsize xsputn(const char* s, std::streamsize n) override {
        terminal_->sputn(s, n);
        capture_->sputn(s, n);
        return n;
    }

private:
    std::streambuf* terminal_;
    std::streambuf* capture_;
};

// ─────────────────────────────────────────────
//  RAII guard: instala el TeeBuffer en cout al
//  construir y lo restaura al destruir.
//  Uso:
//    OutputCapture cap;          // instala
//    ... código normal con cout/cin ...
//    string s = cap.get();       // obtiene captura
//    // destructor restaura cout automáticamente
// ─────────────────────────────────────────────
class OutputCapture {
public:
    OutputCapture() {
        tee_ = new TeeBuffer(std::cout.rdbuf(), capture_.rdbuf());
        original_ = std::cout.rdbuf(tee_);
    }
    ~OutputCapture() {
        std::cout.rdbuf(original_);
        delete tee_;
    }
    std::string get() const { return capture_.str(); }

private:
    std::ostringstream capture_;
    TeeBuffer*         tee_;
    std::streambuf*    original_;
};

// ─────────────────────────────────────────────
//  OUTPUT_DIR: ruta relativa al directorio raíz
//  del proyecto desde el ejecutable.
//  Se puede redefinir antes de incluir este
//  header si la profundidad del subdirectorio
//  es diferente.
//    depth-2 (SortBubble/BubbleArr/):  "../../"
//    depth-3 (Pilas/Arreglos/DatoBase/): "../../../"
// ─────────────────────────────────────────────
#ifndef OUTPUT_DIR
#define OUTPUT_DIR "../../../"
#endif

inline void writeJSON(const std::string& programa, const std::string& salida) {
    std::string path = std::string(OUTPUT_DIR) + "out.json";
    std::string escaped;
    for (char c : salida) {
        if      (c == '"')  escaped += "\\\"";
        else if (c == '\\') escaped += "\\\\";
        else if (c == '\n') escaped += "\\n";
        else if (c == '\r') escaped += "\\r";
        else if (c == '\t') escaped += "\\t";
        else                escaped += c;
    }
    std::ofstream f(path, std::ios::trunc);
    f << "[\n"
      << "  {\n"
      << "    \"programa\": \"" << programa << "\",\n"
      << "    \"salida\": \""   << escaped  << "\"\n"
      << "  }\n"
      << "]\n";
}

inline void writeXML(const std::string& programa, const std::string& salida) {
    std::string path = std::string(OUTPUT_DIR) + "out.xml";
    std::string escaped;
    for (char c : salida) {
        if      (c == '&')  escaped += "&amp;";
        else if (c == '<')  escaped += "&lt;";
        else if (c == '>')  escaped += "&gt;";
        else if (c == '"')  escaped += "&quot;";
        else if (c == '\'') escaped += "&apos;";
        else                escaped += c;
    }
    std::ofstream f(path, std::ios::trunc);
    f << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
      << "<programas>\n"
      << "  <entrada>\n"
      << "    <programa>" << programa << "</programa>\n"
      << "    <salida>"   << escaped  << "</salida>\n"
      << "  </entrada>\n"
      << "</programas>\n";
}

inline void writeCSV(const std::string& programa, const std::string& salida) {
    std::string path = std::string(OUTPUT_DIR) + "out.csv";
    std::string escaped;
    for (char c : salida)
        escaped += (c == '"') ? std::string("\"\"") : std::string(1, c);
    std::ofstream f(path, std::ios::trunc);
    f << "programa,salida\n"
      << "\"" << programa << "\",\"" << escaped << "\"\n";
}

inline void writeTXT(const std::string& programa, const std::string& salida) {
    std::string path = std::string(OUTPUT_DIR) + "out.txt";
    std::ofstream f(path, std::ios::trunc);
    f << "========================================\n"
      << "PROGRAMA: " << programa << "\n"
      << "----------------------------------------\n"
      << salida
      << "========================================\n";
}

inline void writeAllOutputs(const std::string& programa, const std::string& salida) {
    writeJSON(programa, salida);
    writeXML (programa, salida);
    writeCSV (programa, salida);
    writeTXT (programa, salida);
}

#endif // OUTPUT_WRITER_H
