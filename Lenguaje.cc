// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Convertir un NFA en un DFA: Algoritmo de construcción de subconjuntos
// Autor: Eric y Bermúdez Hernández
// Correo: alu0101517476@ull.edu.es
// Fecha: 24/10/2023
// Archivo Lenguaje.h: Implementación de la clase 'Lenguaje'.
// Contiene todas las implementaciones de la clase 'Lenguaje'
// 24/10/2023 - Creación (primera versión) del código

#include "Lenguaje.h"

/**
 * @brief Constructor por defecto
 * 
 */
Lenguaje::Lenguaje() {}

/**
 * @brief Constructor por parámetro que acepta un set de cadenas del que se construye el Lenguaje
 * 
 * @param lenguaje 
 */
Lenguaje::Lenguaje(const std::set<Cadena>& lenguaje) { lenguaje_ = lenguaje; }

/**
 * @brief Constructor por parámetros que acepta una cadena de la que se construye un lenguaje
 * 
 * @param cadena 
 */
Lenguaje::Lenguaje(const Cadena& cadena) { lenguaje_.insert(cadena); }

/**
 * @brief Constructor de copia que permite construir un lenguaje a partir de otro
 * 
 * @param lenguaje2 
 */
Lenguaje::Lenguaje(const Lenguaje& lenguaje2) {
  lenguaje_ = lenguaje2.GetLenguaje();
}

/**
 * @brief Sobrecarga de operador '<<' que permite mostrar un estado por pantalla
 * 
 * @param os 
 * @param lenguaje 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, Lenguaje lenguaje) {
  if (lenguaje.Cardinal() == 0) {
    os << "{}";
  } else {
    size_t contador{1};
    os << "{";
    for (auto& cadena : lenguaje.GetLenguaje()) {
      if (contador != lenguaje.GetLenguaje().size()) {
        os << cadena << ", ";
      } else {
        os << cadena;
      }
      ++contador;
    }
    os << "}";
  }
  return os;
}

/**
 * @brief Sobrecarga de operador '=' que permite igualar 2 lenguajes
 * 
 * @param lenguaje2 
 * @return Lenguaje 
 */
Lenguaje Lenguaje::operator=(const Lenguaje& lenguaje2) {
  lenguaje_ = lenguaje2.GetLenguaje();
  return *this;
}
