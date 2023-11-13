// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 7: Gramáticas en Forma Normal de Chomsky
// Autor: Eric y Bermúdez Hernández
// Correo: alu0101517476@ull.edu.es
// Fecha: 24/10/2023
// Archivo Alfabeto.cc: Implementación de la clase 'Alfabeto'.
// Contiene todas las implementaciones de la clase 'Alfabeto'
// 24/10/2023 - Creación (primera versión) del código

#include "Alfabeto.h"

/**
 * @brief Constructor por parámetros que acepta un set de simbolo del que se
 * contruye el alfabeto
 *
 * @param alfabeto
 */
Alfabeto::Alfabeto(const std::set<Simbolo>& alfabeto) { alfabeto_ = alfabeto; }

/**
 * @brief Constructor de copia que permite contruir un alfabeto a partir de otro
 *
 * @param alfabeto2
 */
Alfabeto::Alfabeto(const Alfabeto& alfabeto2) {
  alfabeto_ = alfabeto2.GetAlfabeto();
}

/**
 * @brief Constructor por parámetro que acepta un símbolo que se inserta al
 * alfabeto
 *
 * @param simbolo
 */
Alfabeto::Alfabeto(const Simbolo& simbolo) {
  // Comprobamos que no se introduzca un símbolo vacío
  if (simbolo.GetSimbolo().empty()) {
    std::cout << "Error, el símbolo que intenta introducir no puede ser un "
                 "símbolo vacío"
              << std::endl;
    exit(1);
  }
  if (simbolo.GetSimbolo() != "&") {
    alfabeto_.insert(simbolo);
  } else {  // Si el símbolo es '&' no se introduce en el alfabeto para no
            // generar confusiones
    std::cout << "Error, ha introducido el símbolo '&' y un alfabeto no puede "
                 "contener dicho símbolo"
              << std::endl;
    exit(1);
  }
}

/**
 * @brief Constructor que a partir de una cadena forma el alfabeto asociado
 *
 * @param cadena
 */
Alfabeto::Alfabeto(const Cadena& cadena) {
  std::set<Simbolo> aux;
  for (const auto& simbolo : cadena.GetCadena()) {
    aux.insert(simbolo);
  }
  Alfabeto alfabeto_aux{aux};
  *this = alfabeto_aux;
}

/**
 * @brief Método que confirma si un símbolo pertenece a un alfabeto, devuelve
 * 'true' si está contenido y 'false' en caso contrario
 *
 * @param simbolo símbolo que queremos comprobar si está en el alfabeto
 * @return true
 * @return false
 */
bool Alfabeto::ContieneElSimbolo(const Simbolo& simbolo) const {
  auto iterador{alfabeto_.find(simbolo)};
  if (iterador != alfabeto_.end()) {
    return true;
  }
  return false;
}

/**
 * @brief Método que sirve para insertar un símbolo en el alfabeto
 * 
 * @param simbolo 
 * @return Alfabeto 
 */
Alfabeto Alfabeto::InsertarSimbolo(const Simbolo& simbolo) {
  alfabeto_.insert(simbolo);
  return *this;
}

/**
 * @brief Sobrecarga de operador '<<' para mostrar un alfabeto por pantalla
 *
 * @param os
 * @param alfabeto alfabeto a mostrar por pantalla
 * @return std::ostream&
 */
std::ostream& operator<<(std::ostream& os, const Alfabeto& alfabeto) {
  os << '{';
  size_t contador{1};
  for (const auto& simbolo : alfabeto.GetAlfabeto()) {
    if (contador != alfabeto.GetAlfabeto().size()) {
      os << simbolo << ", ";
    } else {
      os << simbolo;
    }
    ++contador;
  }
  os << '}';
  return os;
}

/**
 * @brief Sobrecarga de operador '=' para igualar 2 alfabetos
 *
 * @param alfabeto2 segundo alfabeto a igualar el objeto invocante
 * @return Alfabeto
 */
Alfabeto Alfabeto::operator=(const Alfabeto& alfabeto2) {
  alfabeto_ = alfabeto2.GetAlfabeto();
  return *this;
}