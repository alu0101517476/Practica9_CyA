// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 9: Implementación de un simulador de Máquinas de Turing
// Autor: Eric y Bermúdez Hernández
// Correo: alu0101517476@ull.edu.es
// Fecha: 14/11/2023
// Archivo Cinta.h: Definición de la clase 'Cinta'.
// Contiene todas las definiciones de la clase 'Cinta'
// 12/11/2023 - Creación (primera versión) del código

#pragma once

#include <fstream>
#include <iostream>
#include <list>

#include "Alfabeto.h"
#include "Cadena.h"
#include "Estado.h"
#include "Simbolo.h"

// Definimos una variable 'universal' para hacer más fácil el uso de el símbolo
// blanco
const Simbolo blanco{"$"};

class Cinta {
 public:
  // Constructor por defecto
  Cinta();
  // Constructor por parámetros que construye la cinta a partir de un fichero
  Cinta(const std::string& nombre_fichero);
  // Constructor que contruye la cinta a partir de una cadena
  Cinta(const Cadena& cadena);
  // Constructor de copia
  Cinta(Cinta& cinta);
  // Método que permite mover hacia la izquierda la cabeza
  void MoverCabezaALaIzquierda();
  // Método que permite mover a la derecha la cabeza
  void MoverCabezaALaDerecha();
  // Método que devuelve el símbolo actual al que apunta la cabeza
  Simbolo SimboloActual() const { return *cabeza_; }
  // Método que permite agregar un símbolo
  void AgregarSimbolo(const Simbolo& simbolo);
  // Método que permite agregar un símbolo al alfabeto de cinta
  Alfabeto AgregarSimboloAlfabeto(const Simbolo& simbolo);
  // Método que permite reemplazar el símbolo que apunta la cabeza por otro
  Cinta& EscribirSimbolo(const Simbolo& simbolo);
  // Getters
  std::list<Simbolo> GetCinta() { return cinta_; }
  std::list<Simbolo>::iterator GetCabeza() { return cabeza_; }
  Alfabeto GetAlfabetoCinta() const { return alfabeto_cinta_; }
  // Método que dice si un símbolo está en el alfabeto de cinta
  bool EstaEnAlfabeto(const Simbolo& simbolo_alfabeto) const;
  // Método que imprime la cinta mientras se hace la simulación
  void ImprimirCintaTraza(const Estado& estado);
  // sobrecarga de operador >> que permite leer una cinta
  std::istream& operator>>(std::istream& is);
  // Método que permite mostrar una cinta
  friend std::ostream& operator<<(std::ostream& os, const Cinta& cinta);
  // Sobrecarga operador = para igualar 2 cintas
  Cinta& operator=(const Cinta& cinta);

 private:
  Alfabeto alfabeto_cinta_;
  std::list<Simbolo>::iterator cabeza_;
  std::list<Simbolo> cinta_;
};

std::ostream& operator<<(std::ostream& os, const Cinta& cinta);
