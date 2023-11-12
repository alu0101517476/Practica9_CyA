// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Convertir un NFA en un DFA: Algoritmo de construcción de subconjuntos
// Autor: Eric y Bermúdez Hernández
// Correo: alu0101517476@ull.edu.es
// Fecha: 24/10/2023
// Archivo Estado.cc: Implementación de la clase 'Estado'.
// Contiene todas las implementaciones de la clase 'Estado'
// 24/10/2023 - Creación (primera versión) del código

#include "Estado.h"

/**
 * @brief Constructor por defecto
 * 
 */
Estado::Estado() {
  identificador_ = "";
  aceptado_ = false;
}

/**
 * @brief Constructor de copia con el que construimos un estado a partir de otro
 * 
 * @param estado del que contruimos el estado invocante
 */
Estado::Estado(const Estado& estado) {
  identificador_ = estado.GetIdentificador();
  aceptado_ = estado.GetAceptado();
}

/**
 * @brief Sobrecarga de operador '<', útil para la clase 'AutomataFinito' para poder crear el map de estados
 * 
 * @param estado2 segundo estado a comparar
 * @return true 
 * @return false 
 */
// Sobrevarga de operadores de comparación
bool Estado::operator<(const Estado& estado2) const {
  return identificador_ < estado2.GetIdentificador();
}

/**
 * @brief Sobrecarga de operador '==', útil para la clase 'AutomataFinito' para poder crear el map de estados
 * 
 * @param estado2 segundo estado a comparar
 * @return true 
 * @return false 
 */
bool Estado::operator==(const Estado& estado2) const {
  return identificador_ == estado2.GetIdentificador();
}

/**
 * @brief Sobrecarga operador '=' para poder igualar 2 estádos
 * 
 * @param estado2 segundo estado a igualar
 * @return Estado 
 */
Estado Estado::operator=(const Estado& estado2) {
  identificador_ = estado2.GetIdentificador();
  aceptado_ = estado2.GetAceptado();
  return *this;
}

/**
 * @brief Sobrecarga de operador << para imprimir un estado por pantalla
 * 
 * @param os 
 * @param estado Estado a mostrar por pantalla
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const Estado& estado) {
  os << estado.identificador_ << " " << estado.aceptado_ << std::endl;
  return os;
}

/**
 * @brief Sobrecarga de operador >> para leer un estado
 * 
 * @param is 
 * @param estado estado a leer
 * @return std::istream& 
 */
std::istream& operator>>(std::istream& is, Estado& estado) {
  is >> estado.identificador_ >> estado.aceptado_;
  return is;
}