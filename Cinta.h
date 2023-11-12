#pragma once

#include <iostream>
#include <list>
#include <fstream>

#include "Alfabeto.h"
#include "Simbolo.h"
#include "Cadena.h"

// Definimos una variable 'universal' para hacer más fácil el uso de el símbolo blanco
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
  Cinta(const Cinta& cinta);
  // Método que permite mover hacia la izquierda la cabeza
  void MoverALaIzquierda();
  // Método que permite mover a la derecha la cabeza
  void MoverALaDerecha();
  // Método que permite agregar un símbolo
  Cinta AgregarSimbolo(const Simbolo& simbolo);
  // Getters
  std::list<Simbolo> GetCinta() const { return cinta_; }
  Simbolo* GetCabeza() const { return cabeza_; }
  Alfabeto GetAlfabetoCinta() const { return alfabeto_cinta_; }
  // sobrecarga de operador >> que permite leer una cinta 
  std::istream& operator>>(std::istream& is);
  // Método que permite mostrar una cinta
  friend std::ostream& operator<<(std::ostream& os, const Cinta& cinta);
  // Sobrecarga operador = para igualar 2 cintas
  Cinta operator=(const Cinta& cinta);
 private:
  Alfabeto alfabeto_cinta_;
  Simbolo* cabeza_;
  std::list<Simbolo> cinta_;
};

std::ostream& operator<<(std::ostream& os, const Cinta& cinta);
