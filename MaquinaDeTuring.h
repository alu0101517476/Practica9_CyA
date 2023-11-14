// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 9: Implementación de un simulador de Máquinas de Turing
// Autor: Eric y Bermúdez Hernández
// Correo: alu0101517476@ull.edu.es
// Fecha: 14/11/2023
// Archivo MaquinaDeTuring.h: Definición de la clase 'MaquinaDeTuring'.
// Contiene todas las definiciones de la clase 'MaquinaDeTuring'
// 12/11/2023 - Creación (primera versión) del código

#pragma once

#include <fstream>
#include <iostream>
#include <sstream>

#include "Cinta.h"
#include "Simbolo.h"
#include "Transicion.h"

class MaquinaDeTuring {
 public:
  // Constructor que construye a partir de un fichero la MT
  MaquinaDeTuring(const std::string& nombre_fichero_mt,
                  const std::string& nombre_fichero_cinta);
  // Constructor de copia
  MaquinaDeTuring(const MaquinaDeTuring& maquina2);
  // Método que permite buscar y devolver un estado dentro de el conjunto de
  // estados de la MT
  Estado BuscarEstado(const std::string& identificador_estado);
  // Método que permite simular el funcionamiento de una MT
  bool SimulacionMT();
  // Método que dice si la cadena es aceptada o no
  void EsAceptada();
  // Getters
  Cinta GetCinta() { return cinta_; }
  Transicion& GetFuncionTransicion() { return funcion_transicion_; }
  // Sobrecarga operador = para igualar 2 máquinas de turing
  MaquinaDeTuring& operator=(const MaquinaDeTuring& maquina2);
  // Sobrecarga de operador << para poder mostrar la MT por pantalla
  friend std::ostream& operator<<(std::ostream& os,
                                  const MaquinaDeTuring& maquina);

 private:
  int numero_estados_;
  int numero_tuplas_;
  std::set<Estado> conjunto_estados_;
  Cinta cinta_;
  Estado estado_inicial_;
  std::set<Estado> estados_aceptacion_;
  Transicion funcion_transicion_;
};

std::ostream& operator<<(std::ostream& os, const MaquinaDeTuring& maquina);
