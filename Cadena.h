// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Convertir un NFA en un DFA: Algoritmo de construcción de subconjuntos
// Autor: Eric y Bermúdez Hernández
// Correo: alu0101517476@ull.edu.es
// Fecha: 24/10/2023
// Archivo Cadena.h: Definición de la clase 'Cadena'.
// Contiene todas las definiciones de la clase 'Cadena'
// 24/10/2023 - Creación (primera versión) del código

#pragma once

#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

#include "Alfabeto.h"
#include "Lenguaje.h"
#include "Simbolo.h"

class Alfabeto;

class Simbolo;

class Lenguaje;

class Cadena {
 public:
  // Constructor por defecto
  Cadena();
  // Constructor de copia
  Cadena(const Cadena& cadena);
  // Constructor por parámetros
  Cadena(const std::vector<Simbolo>& cadena);
  // Constructor por parámetros que acepta un string
  Cadena(const std::string& cadena);
  // Constructor por parámetros que acepta un char
  Cadena(const char& simbolo);
  // Constructor por parámetros que acepta un Símbolo
  Cadena(const Simbolo& simbolo);
  // Getter
  std::vector<Simbolo> GetCadena() const { return cadena_; }
  // Método que devuelve el tamaño de una cadena
  size_t Size() const;
  // Método que te devuelve la cadena inversa
  Cadena Inversa();
  // Método que muestra todos los prefijos
  Lenguaje Prefijo();
  // Método que muestra todos los sufijos
  Lenguaje Sufijo();
  // Sobrecarga operador<<
  friend std::ostream& operator<<(std::ostream& os, const Cadena& cadena);
  friend std::istream& operator>>(std::istream& is, Cadena& cadena);
  // Sobrecarga operador =
  Cadena operator=(const Cadena& cadena2);
  // Sobrecarga operador <
  bool operator<(const Cadena& cadena2) const;
  // Sobrecarga operador ==
  bool operator==(const Cadena& cadena2) const;
  // Sobrecarga operador[] que nos permite acceder
  Simbolo operator[](int posicion) const;

 private:
  std::vector<Simbolo> cadena_;
};

std::ostream& operator<<(std::ostream& os, const Cadena& cadena);
std::istream& operator>>(std::istream& is, Cadena& cadena);
