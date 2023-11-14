// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 9: Implementación de un simulador de Máquinas de Turing
// Autor: Eric y Bermúdez Hernández
// Correo: alu0101517476@ull.edu.es
// Fecha: 14/11/2023
// Archivo Simbolo.h: Definición de la clase 'Simbolo'.
// Contiene todas las definiciones de la clase 'Simbolo'
// 12/11/2023 - Creación (primera versión) del código

#pragma once

#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

#include "Alfabeto.h"

class Simbolo {
  // Constructores
 public:
  // Constructor por defecto
  Simbolo();
  // Constructor por parámetro
  Simbolo(const std::string& simbolo);
  // Constructor por parámetro con char
  Simbolo(const char& simbolo);
  // Constructor de copia
  Simbolo(const Simbolo& Simbolo);
  // Getter
  std::string GetSimbolo() const { return simbolo_; }
  // Método que dice si un símbolo es terminal o no
  bool EsTerminal();
  // Operador << para mostrar por pantalla
  friend std::ostream& operator<<(std::ostream& os, const Simbolo& simbolo);
  // Operador >> para permitir leer
  friend std::istream& operator>>(std::istream& is, Simbolo& Simbolo);
  // Operador para igualar símbolos
  Simbolo operator=(const Simbolo& simbolo2);
  // Operador para comparar si 2 símbolos son iguales
  bool operator==(const Simbolo& simbolo2) const;
  // Operador < necesario para set de símbolos usado en otra clase
  bool operator<(const Simbolo& simbolo2) const;

 private:
  std::string simbolo_;
};

std::ostream& operator<<(std::ostream& os, const Simbolo& simbolo);
std::istream& operator>>(std::istream& is, const Simbolo& Simbolo);
