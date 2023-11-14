// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 9: Implementación de un simulador de Máquinas de Turing
// Autor: Eric y Bermúdez Hernández
// Correo: alu0101517476@ull.edu.es
// Fecha: 14/11/2023
// Archivo Transicion.h: Definición de la clase 'Transicion'.
// Contiene todas las definiciones de la clase 'Transicion'
// 12/11/2023 - Creación (primera versión) del código

#pragma once

#include <iostream>
#include <map>

#include "Estado.h"
#include "Simbolo.h"

struct TernaTransicion {
  Estado estado_siguiente_;
  Simbolo simbolo_escritura_;
  char movimiento_cabeza_;
};

class Transicion {
 public:
  // Constructor por defecto
  Transicion();
  // Constructor por parámetros
  Transicion(
      const std::map<std::pair<Estado, Simbolo>, TernaTransicion>& transiciones)
      : transiciones_{transiciones} {}
  // Constructor de copia
  Transicion(const Transicion& transicion2) { *this = transicion2; }
  // Método que comprueba si el movimiento de la cabeza de la transición no es
  // correcto
  bool EsMovimientoCorrecto(const char& movimiento_cabeza) const;
  // Métodos que permiten agregar una transición
  std::map<std::pair<Estado, Simbolo>, TernaTransicion> AgregarTransicion(
      std::pair<Estado, Simbolo> pareja, Simbolo simbolo_escritura,
      char movimiento_cabeza, Estado estado_siguiente);
  // Métodos que permiten agregar una transición
  std::map<std::pair<Estado, Simbolo>, TernaTransicion> AgregarTransicion(
      std::pair<Estado, Simbolo> pareja, TernaTransicion terna);
  // Getter
  std::map<std::pair<Estado, Simbolo>, TernaTransicion> GetTransiciones()
      const {
    return transiciones_;
  }
  // Método que devuelve el número de transiciones que hay
  size_t Size() const { return transiciones_.size(); }
  // Método que dado el estado y un símbolo dice si hay transición para ese par
  bool ExisteTrancision(std::pair<Estado, Simbolo> celda_actual) const;
  // Sobrecarga de operador << para mostrar las transiciones por pantalla
  friend std::ostream& operator<<(std::ostream& os,
                                  const Transicion& transicion);
  // Sobrecarga operador = para igualar 2 transiciones
  Transicion operator=(const Transicion& transicion2);
  // Sobrecarga operador [] para poder acceder cómodamente a la terna
  TernaTransicion operator[](const std::pair<Estado, Simbolo>& celda_actual);

 private:
  std::map<std::pair<Estado, Simbolo>, TernaTransicion> transiciones_;
};

std::ostream& operator<<(std::ostream& os, const Transicion& transicion);
