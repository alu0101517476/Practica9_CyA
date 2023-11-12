// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 7: Gramáticas en Forma Normal de Chomsky
// Autor: Eric y Bermúdez Hernández
// Correo: alu0101517476@ull.edu.es
// Fecha: 24/10/2023
// Archivo Alfabeto.h: Definición de la clase 'Alfabeto'.
// Contiene todas las definiciones de la clase 'Alfabeto'
// 24/10/2023 - Creación (primera versión) del código

#pragma once

#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

#include "Cadena.h"
#include "Simbolo.h"

class Simbolo;

class Cadena;

class Alfabeto {
 public:
  // Constructor por defecto
  Alfabeto() = default;
  // Constructor por parámetro que acepta un set de símbolos
  Alfabeto(const std::set<Simbolo>& alfabeto);
  // Constructor por parámetro que acepta un Simbolo
  Alfabeto(const Simbolo& simbolo);
  // Constructor que a partir de una cadena forma el alfabeto asociado
  Alfabeto(const Cadena& cadena);
  // Constructor de copia
  Alfabeto(const Alfabeto& alfabeto2);
  // Método que confirma si un símbolo pertenece a un alfabeto
  bool ContieneElSimbolo(const Simbolo& simbolo);
  // Getter
  std::set<Simbolo> GetAlfabeto() const { return alfabeto_; }
  // Setter
  void SetAlfabeto(const std::set<Simbolo>& alfabeto) { alfabeto_ = alfabeto; }
  // Método que te devuelve el cardinal de un alfabeto
  size_t Cardinal() const { return alfabeto_.size(); }
  // Método que inserta un símbolo en el alfabeto
  Alfabeto InsertarSimbolo(const Simbolo& simbolo);
  // Sobrecarga operador<< para mostrar por pantalla
  friend std::ostream& operator<<(std::ostream& os, const Alfabeto& alfabeto);
  // Sobrecarga del operador =
  Alfabeto operator=(const Alfabeto& alfabeto2);

 private:
  std::set<Simbolo> alfabeto_;
};

std::ostream& operator<<(std::ostream& os, const Alfabeto& alfabeto);
