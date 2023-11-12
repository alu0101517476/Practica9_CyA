// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Convertir un NFA en un DFA: Algoritmo de construcción de subconjuntos
// Autor: Eric y Bermúdez Hernández
// Correo: alu0101517476@ull.edu.es
// Fecha: 24/10/2023
// Archivo Cadena.cc: Implementación de la clase 'Cadena'.
// Contiene todas las implementaciones de la clase 'Cadena'
// 24/10/2023 - Creación (primera versión) del código

#include "Cadena.h"

/**
 * @brief Constructor por defecto
 *
 */
Cadena::Cadena() {
  // Si no se pasa ningún símbolo, es que la cadena no tiene por lo que será la
  // cadena vacía
  Simbolo simbolo{"&"};
  cadena_.emplace_back(simbolo);
}

/**
 * @brief // Constructor por parámetros, le pasamos un vector de símbolos y a
 * partir de este se genera la cadena
 *
 * @param cadena
 */
Cadena::Cadena(const std::vector<Simbolo>& cadena) { cadena_ = cadena; }

/**
 * @brief Constructor por parámetros que acepta un string, útil para leer del
 * fichero y construir las cadenas directamente
 *
 * @param cadena
 */
Cadena::Cadena(const std::string& cadena) {
  Simbolo simbolo{cadena};
  std::vector<Simbolo> aux;
  for (size_t i{0}; i < simbolo.GetSimbolo().size(); ++i) {
    aux.emplace_back(static_cast<Simbolo>(simbolo.GetSimbolo()[i]));
  }
  cadena_ = aux;
}

/**
 * @brief Constructor por parámetros que acepta un char
 *
 * @param simbolo
 */
Cadena::Cadena(const char& simbolo) { cadena_.emplace_back(Simbolo(simbolo)); }

/**
 * @brief Constructor por parámetros que acepta un Símbolo
 *
 * @param simbolo
 */
Cadena::Cadena(const Simbolo& simbolo) { cadena_.emplace_back(simbolo); }

/**
 * @brief Constructor de copia que nos permite construir una cadena a partir de
 * otra
 *
 * @param cadena
 */
Cadena::Cadena(const Cadena& cadena) { cadena_ = cadena.GetCadena(); }

/**
 * @brief Método que nos devuelve el tamaño de una cadena
 *
 * @return size_t
 */
size_t Cadena::Size() const {
  if (cadena_[0].GetSimbolo() == "&" && cadena_.size() == 1) {
    // Si la cadena solo tiene un elemento y es '&' es que es la cadena vacía,
    // por lo que tiene de longitud 0
    return 0;
  }
  return cadena_.size();
}

/**
 * @brief // Método que calcula la inversa de una cadena, devolviendo una cadena
 * inversa sin modificar a la cadena invocante del método
 *
 * @return Cadena
 */
Cadena Cadena::Inversa() {
  // Creamos un vector de símbolos auxiliar el cual igualamos al vector de el
  // objeto invocante y le damos la vuelta, devolviendo el objeto construido con
  // el vector invertido
  std::vector<Simbolo> aux{cadena_};
  std::reverse(aux.begin(), aux.end());
  return Cadena{aux};
}

/**
 * @brief Método que devuelve un lenguaje con todos los prefijos de una cadena
 *
 * @return Lenguaje
 */
Lenguaje Cadena::Prefijo() {
  std::set<Cadena> lenguaje_aux{Cadena()};
  Cadena cadena_aux{""};
  for (const auto& simbolo : this->GetCadena()) {
    cadena_aux.cadena_.push_back(simbolo);
    lenguaje_aux.insert(cadena_aux);
  }
  return Lenguaje{lenguaje_aux};
}

/**
 * @brief Método que devuelve un lenguaje con todos los sufijos de una cadena
 *
 * @return Lenguaje
 */
Lenguaje Cadena::Sufijo() {
  std::set<Cadena> lenguaje_aux{Cadena()};
  Cadena cadena_aux{""};
  for (auto simbolo{this->cadena_.rbegin()}; simbolo != this->cadena_.rend();
       ++simbolo) {
    cadena_aux.cadena_.push_back(*simbolo);
    lenguaje_aux.insert(cadena_aux.Inversa());
  }
  return Lenguaje{lenguaje_aux};
}

/**
 * @brief Sobrecarga operador '<<' para mostrar la Cadena por pantalla
 *
 * @param os
 * @param cadena cadena a mostrar por pantalla
 * @return std::ostream&
 */
std::ostream& operator<<(std::ostream& os, const Cadena& cadena) {
  for (const auto& simbolo : cadena.cadena_) {
    os << simbolo;
  }
  return os;
}

/**
 * @brief Sobrecarga de operador '>>' para poder leer una cadena
 *
 * @param is
 * @param cadena cadena a leer
 * @return std::istream&
 */
std::istream& operator>>(std::istream& is, Cadena& cadena) {
  std::string aux;
  is >> aux;
  Simbolo simbolo{aux};
  std::vector<Simbolo> cadena_aux{simbolo};
  cadena.cadena_ = cadena_aux;
  return is;
}

Cadena Cadena::operator=(const Cadena& cadena2) {
  cadena_ = cadena2.GetCadena();
  return *this;
}

// Sobrecarga de operador =
bool Cadena::operator<(const Cadena& cadena2) const {
  return cadena_ < cadena2.GetCadena();
}

bool Cadena::operator==(const Cadena& cadena2) const {
  return cadena_ == cadena2.GetCadena();
}

// Sobrecarga operador[] que nos permite acceder
Simbolo Cadena::operator[](int posicion) const { return cadena_[posicion]; }
