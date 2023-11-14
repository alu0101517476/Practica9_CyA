// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 9: Implementación de un simulador de Máquinas de Turing
// Autor: Eric y Bermúdez Hernández
// Correo: alu0101517476@ull.edu.es
// Fecha: 14/11/2023
// Archivo Simbolo.h: Implementación de la clase 'Simbolo'.
// Contiene todas las implementaciones de la clase 'Simbolo'
// 12/11/2023 - Creación (primera versión) del código

#include "Simbolo.h"

/**
 * @brief Constructor por defecto, si no se pasa ningún parámetro el símbolo es
 * vacío
 *
 */
Simbolo::Simbolo() { simbolo_ = ""; }

/**
 * @brief Constructor por parámetros
 *
 * @param simbolo
 */
Simbolo::Simbolo(const std::string& simbolo) { simbolo_ = simbolo; }

/**
 * @brief Constructor por parámetros con char
 *
 * @param simbolo
 */
Simbolo::Simbolo(const char& simbolo) { simbolo_ = simbolo; }

/**
 * @brief Constructor de copia del que construimos un símbolo a partir de otro
 *
 * @param simbolo segundo símbolo del que construimos el símbolo invocante
 */
Simbolo::Simbolo(const Simbolo& simbolo) { simbolo_ = simbolo.GetSimbolo(); }

/**
 * @brief Método que dice si un símbolo es terminal o no
 *
 * @return true
 * @return false
 */
bool Simbolo::EsTerminal() {
  if (std::islower(simbolo_[0])) {
    return true;
  }
  return false;
}

/**
 * @brief Sobrecarga de operador '<<' para mostrar un símbolo por pantalla
 *
 * @param os
 * @param simbolo símbolo a mostrar por pantalla
 * @return std::ostream&
 */
std::ostream& operator<<(std::ostream& os, const Simbolo& simbolo) {
  os << simbolo.GetSimbolo();
  return os;
}

/**
 * @brief Sobrecarga de operador '>>' para leer un símbolo
 *
 * @param is
 * @param simbolo símbolo a leer
 * @return std::istream&
 */
std::istream& operator>>(std::istream& is, Simbolo& simbolo) {
  is >> simbolo.simbolo_;
  return is;
}

/**
 * @brief Sobrecarga de operador '=' para igualar 2 símbolos
 *
 * @param simbolo2
 * @return Simbolo
 */
Simbolo Simbolo::operator=(const Simbolo& simbolo2) {
  simbolo_ = simbolo2.GetSimbolo();
  return *this;
}

/**
 * @brief Sobrecarga de operador '==' para poder comparar 2 símbolos, útil para
 * la clase alfabeto y poder crear un set de estados
 *
 * @param simbolo2 segundo símbolo a comparar
 * @return true
 * @return false
 */
bool Simbolo::operator==(const Simbolo& simbolo2) const {
  const Simbolo aux{*this};
  return aux.GetSimbolo() == simbolo2.GetSimbolo();
}

/**
 * @brief Sobrecarga de operador '<' para poder comparar 2 símbolos, útil para
 * la clase alfabeto y poder crear un set de estados
 *
 * @param simbolo2 segundo símbolo a comparar
 * @return true
 * @return false
 */
bool Simbolo::operator<(const Simbolo& simbolo2) const {
  const Simbolo aux{*this};
  return aux.GetSimbolo() < simbolo2.GetSimbolo();
}