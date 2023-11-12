#pragma once

#include <iostream>
#include <fstream>
#include <sstream>

#include "Cinta.h"
#include "Transicion.h"

class MaquinaDeTuring {
 public:
  // Constructor que construye a partir de un fichero la MT
  MaquinaDeTuring(const std::string& nombre_fichero);
  // Método que permite buscar y devolver un estado dentro de el conjunto de estados de la MT
  Estado BuscarEstado(const std::string& identificador_estado);
  // Sobrecarga de operador << para poder mostrar la MT por pantalla
  friend std::ostream& operator<<(std::ostream& os, const MaquinaDeTuring& maquina);
 private:
  int numero_estados_;
  int numero_tuplas_;
  std::set<Estado> conjunto_estados_;
  Cinta cinta_;
  Alfabeto alfabeto_entrada_;
  Estado estado_inicial_;
  std::set<Estado> estados_aceptacion_;
  Transicion funcion_transicion_;
};

std::ostream& operator<<(std::ostream& os, const MaquinaDeTuring& maquina);
