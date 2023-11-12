// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 6: Convertir un NFA en un DFA: Algoritmo de construcción de subconjuntos
// Autor: Eric y Bermúdez Hernández
// Correo: alu0101517476@ull.edu.es
// Fecha: 24/10/2023
// Archivo Estado.h: Definición de la clase 'Estado'.
// Contiene todas las definiciones de la clase 'Estado'
// 24/10/2023 - Creación (primera versión) del código

#pragma once

#include <iostream>
#include <map>

#include "Simbolo.h"
#include "Alfabeto.h"
#include "Cadena.h"
#include "Lenguaje.h"

class Alfabeto;

class Lenguaje;

class Cadena;

class Simbolo;

/**
 * @brief Clase que definimos para representar un estado
 * 
 */
class Estado {
 public:
  // Constructor por defecto, crea una '&' transición
  Estado();
  // Construcor por parámetros que crea un estado
  Estado(const std::string& identificador, bool aceptado) : identificador_{identificador}, aceptado_{aceptado} {}
  Estado (const char& identificador, bool aceptado) : identificador_{identificador}, aceptado_{aceptado} {}
  // Construcor por parámetros que crea un estado, aceptando un identificador entero
  Estado(const int& identificador, bool aceptado) : identificador_{std::to_string(identificador)}, aceptado_{aceptado} {}
  // Constructor de copia
  Estado(const Estado& estado);
  // Getters
  bool GetAceptado() const { return aceptado_; }
  std::string GetIdentificador() const { return identificador_; }
  // Setters
  void SetAceptado(const bool aceptado) { aceptado_ = aceptado; }
  void SetIdentificador(const std::string& identificador) { identificador_ = identificador; }
  // Sobrecarga de operadores de comparación, útil para la clase 'AutomataFinito'
  bool operator<(const Estado& estado2) const;
  bool operator==(const Estado& estado2) const;
  // Sobrecarga de operador = para igualar un estado a otro
  Estado operator=(const Estado& estado2);
  // Sobrecarga de operador << para mostrar en pantalla el estado
  friend std::ostream& operator<<(std::ostream& os, const Estado& estado);
  friend std::istream& operator>>(std::istream& is, Estado& estado);
 private:
  std::string identificador_;
  bool aceptado_;
};

std::ostream& operator<<(std::ostream& os, const Estado& estado);
std::istream& operator>>(std::istream& is, Estado& estado);
