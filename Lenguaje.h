// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 9: Implementación de un simulador de Máquinas de Turing
// Autor: Eric y Bermúdez Hernández
// Correo: alu0101517476@ull.edu.es
// Fecha: 14/11/2023
// Archivo Lenguaje.h: Definición de la clase 'Lenguaje'.
// Contiene todas las definiciones de la clase 'Lenguaje'
// 12/11/2023 - Creación (primera versión) del código

#pragma once

#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

#include "Alfabeto.h"
#include "Cadena.h"

class Cadena;

class Lenguaje {
  // Constructores
 public:
  // Constructor por defecto
  Lenguaje();
  // Constructor por parámetros que acepta un set de cadenas
  Lenguaje(const std::set<Cadena>& lenguaje);
  // Constructor por parámetros que acepta una cadena
  Lenguaje(const Cadena& cadena);
  // Constructor de copia
  Lenguaje(const Lenguaje& lenguaje2);
  // Getter
  std::set<Cadena> GetLenguaje() const { return lenguaje_; }
  // Método que devuelve el cardinal del lenguaje
  size_t Cardinal() const { return lenguaje_.size(); };
  // Sobrecarga de operador << para mostrar por pantalla un lenguaje
  friend std::ostream& operator<<(std::ostream& os, Lenguaje lenguaje);
  Lenguaje operator=(const Lenguaje& lenguaje2);

 private:
  std::set<Cadena> lenguaje_;
};

std::ostream& operator<<(std::ostream& os, Lenguaje lenguaje);
