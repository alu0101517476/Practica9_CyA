#pragma once

#include <iostream>
#include <map>

#include "Estado.h"
#include "Simbolo.h"

struct TernaTransicion {
  TernaTransicion(Estado estado_siguiente, Simbolo simbolo_escritura,
                  char movimiento_cabeza)
      : estado_siguiente_{estado_siguiente},
        simbolo_escritura_{simbolo_escritura},
        movimiento_cabeza_{movimiento_cabeza} {}
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
  // Sobrecarga de operador << para mostrar las transiciones por pantalla
  friend std::ostream& operator<<(std::ostream& os,
                                  const Transicion& transicion);
  // Sobrecarga operador = para igualar 2 transiciones
  Transicion operator=(const Transicion& transicion2);

 private:
  std::map<std::pair<Estado, Simbolo>, TernaTransicion> transiciones_;
};

std::ostream& operator<<(std::ostream& os, const Transicion& transicion);
