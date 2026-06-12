## 💻 Abstracción y uso de datos / IPN - UPIICSA 💻
  
**Secuencia:** 3CM30  
**Docente:** Entzana Garduño Yventz  
**Carrera:** Licenciatura en Ciencias de la Informática

## Autores  
- Carrera Rojo Jane Adriana
- Flores Maya Valeria
- Frías Martinez Vanessa Judith
- Martinez Valencia Karla Itzel
- Saavedra Rodríguez Aarón Emanuel

---

## Contenido
El presente repositorio contiene en su totalidad las prácticas para los tres departamentales de la asignatura "Abstracción y uso de datos", obedeciendo la siguiente estructura:
## Primer Departamental
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Se abarcan los fundamentos de la programación orientada a objetos en C++. Se trabajó con la definición de clases y structs, comparando sus diferencias en cuanto a acceso y representación en memoria mediante el operador sizeof. Se usaron arreglos de objetos para almacenar colecciones de datos, y se organizó el código en archivos separados de encabezado y de implementación (.h y .cpp).
Se practicó la sobrecarga de funciones para manejar distintos números de parámetros en una misma operación, la herencia para extender clases base sin modificarlas, y la sobreescritura de métodos virtuales para cambiar el comportamiento heredado. Finalmente, se aplicó la recursividad para calcular elementos en estructuras fractales como el triángulo de Sierpinski y el conjunto de Cantor.  

---

## Segundo Departamental  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Se enfoca en estructuras de datos y algoritmos de ordenamiento, organizado en cuatro grandes temas: estructuras de datos lineales (Listas, Pilas y Colas), implementadas cada una de tres formas distintas (con arreglos, con punteros y usando librerías estándar), y variantes de tipo de dato (dato base vs. nuevo dato); y algoritmos de ordenamiento (Bubble Sort, Quick Sort y Merge Sort), también implementados tanto con arreglos como con punteros.

---

## Tercer Departamental  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Se crean dos proyectos clon de 1erDep y 2doDep que implementan el archivo compartido output_writer.h en la raíz del proyecto, centralizando toda la lógica de escritura a cuatro archivos de salida. Este header contiene la clase TeeBuffer y OutputCapture, que permiten capturar la salida de cout en tiempo real sin interrumpir la interacción con el usuario, así como las funciones writeJSON, writeXML, writeCSV y writeTXT que generan los archivos out.json, out.xml, out.csv y out.txt en la raíz del proyecto con el nombre del programa y su salida correspondiente.
A nivel de cada programa, todos los main.cpp fueron modificados para incluir output_writer.h e instanciar un OutputCapture al inicio, de modo que toda la sesión quede capturada y escrita a los archivos al terminar.

---

## Compilación y Ejecución
A continuación se detalla cómo compilar y ejecutar los proyectos de este repositorio en un entorno de trabajo Linux. El usuario debe contar con una instalación previa de g++ y git.  
### 1. Clonar el repositorio
```bash
git clone https://github.com/CrimsonBlood45/AbstraccionyUD
```  
### 2. Compilar  
Posicionado en la carpeta del proyecto que se quiere compilar. Colocar el nombre deseado para el ejecutable en lugar de "nombredelejecutable":  
```bash
g++ main.cpp -o "nombredelejecutable"
```
### 3. Ejecución  
Habiendo compilado y estando posicionado en la carpeta del proyecto que se quiere ejecutar:  
```bash
./"nombredelejecutable"
```
