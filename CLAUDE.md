# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

Academic repository for the course "Abstracción y uso de datos" (IPN - UPIICSA, 3CM30). All code is C++ organized into three departmental units (`1erDep`, `2doDep`, `3erDep`).

## Build & Run

Each project is self-contained in its own folder. Compile from within the project directory:

```bash
# Navigate to the specific project
cd 2doDep/Pilas/Arreglos/DatoBase

# Compile (include all .cpp files in the same folder)
g++ main.cpp pila.cpp -o pila

# Run
./pila
```

For projects with only a `main.cpp` and a header-only implementation:
```bash
g++ main.cpp -o ejecutable
./ejecutable
```

Projects in `3erDep/` require compiling from inside each program subfolder so that `output_writer.h`'s `OUTPUT_DIR "../"` resolves correctly — the output files (`out.json`, `out.xml`, `out.csv`, `out.txt`) are written one level up from where the binary runs.

## Architecture

### Departmental structure

**`1erDep/`** — OOP fundamentals: classes/structs, operator `sizeof`, arrays of objects, separate `.h`/`.cpp` files, function overloading, inheritance, virtual method overriding, and recursion (Sierpinski/Cantor).

**`2doDep/`** — Data structures and sorting algorithms:
- `Pilas/`, `Listas/`, `Colas/` — each implemented three ways: `Arreglos/` (arrays), `Punteros/` (raw pointers / linked nodes), `Librerías/` (STL). Each variant comes in `DatoBase/` (plain `int`) and `NuevoDato/` (custom struct/class).
- Abstract base classes (`pilaadt.h`, `listaadt.h`, `colaadt.h`) define the interface; concrete subclasses in each implementation folder inherit from them.
- `SortBubble/`, `SortQuick/`, `SortMerge/` — each with `*Arr/` (array) and `*Ptr/` (pointer) variants.
- Top-level `menupila.h/.cpp`, `menulista.h/.cpp`, `menucola.h/.cpp` provide shared interactive menus used across implementations.

**`3erDep/`** — Clones of 1erDep and 2erDep projects modified to capture and persist output:
- `1erDep_outs/` and `2doDep_outs/` mirror the original structures but each `main.cpp` instantiates `OutputCapture` at startup.
- A shared `output_writer.h` at the root of each clone (`3erDep/1erDep_outs/output_writer.h`, `3erDep/2doDep_outs/output_writer.h`) is `#include`d by every `main.cpp`.
- `DigrafoCasa/` contains a directed graph (digraph) dataset in four formats (`.txt`, `.json`, `.xml`, `.csv`) representing Mexico City transit routes.

### Key shared header: `output_writer.h`

Used exclusively in `3erDep/`. Provides:
- `TeeBuffer` — `streambuf` subclass that mirrors every `cout` write to both the terminal and an in-memory `ostringstream`.
- `OutputCapture` — RAII guard that installs the `TeeBuffer` on construction and restores the original `cout` on destruction. Usage pattern in every `main.cpp`: declare `OutputCapture cap;` as the first thing in `main`, run the program normally, then call `writeAllOutputs(programName, cap.get())` at the end.
- `writeJSON`, `writeXML`, `writeCSV`, `writeTXT`, `writeAllOutputs` — write session output to `../out.*` (relative to the binary's working directory).

### ADT pattern (2erDep / 3erDep)

Abstract base (`*adt.h`) → concrete subclass per implementation strategy. The `menu*.h/.cpp` files call through the ADT interface, so they work with any concrete implementation linked in.
