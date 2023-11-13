#include "Transicion.h"

/**
 * @brief Constructor por defecto
 *
 */
Transicion::Transicion() {}

/**
 * @brief Método que comprueba si el movimiento de la cabeza de la transición no
 * es correcto
 *
 * @param movimiento_cabeza movimiento de la cabeza que puede ser L,R o S
 * @return true
 * @return false
 */
bool Transicion::EsMovimientoCorrecto(const char& movimiento_cabeza) const {
  if (movimiento_cabeza == 'L' || movimiento_cabeza == 'R' ||
      movimiento_cabeza == 'S') {
    return true;
  }
  return false;
}

/**
 * @brief Método que permite agregar una transición
 *
 * @param pareja Par que contiene el estado actual y el símbolo actual
 * @param estado_siguiente Estado siguiente al que se transita
 * @param simbolo_escritura Símbolo que escribimos en la cinta
 * @param movimiento_cabeza Movimiento de la cabeza(L,R,S)
 * @return std::map<std::pair<Estado, Simbolo>, TernaTransicion>
 */
std::map<std::pair<Estado, Simbolo>, TernaTransicion>
Transicion::AgregarTransicion(std::pair<Estado, Simbolo> pareja,
                              Simbolo simbolo_escritura, char movimiento_cabeza,
                              Estado estado_siguiente) {
  transiciones_.insert(
      {pareja, TernaTransicion{estado_siguiente, simbolo_escritura,
                               movimiento_cabeza}});
  return transiciones_;
}
// Métodos que permiten agregar una transición
/**
 * @brief Método que permite agregar una transición
 *
 * @param pareja Par que contiene el estado actual y el símbolo actual
 * @param terna Terna que contiene el estado siguiente, el símbolo de escritura
 * y el movimiento de la cabeza
 * @return std::map<std::pair<Estado, Simbolo>, TernaTransicion>
 */
std::map<std::pair<Estado, Simbolo>, TernaTransicion>
Transicion::AgregarTransicion(std::pair<Estado, Simbolo> pareja,
                              TernaTransicion terna) {
  transiciones_.insert({pareja, terna});
  return transiciones_;
}

/**
 * @brief Método que dado el estado y un símbolo dice si hay transición para ese
 * par
 *
 * @param celda_actual estado y símbolo que lee la cabeza de la cinta
 * @return true
 * @return false
 */
bool Transicion::ExisteTrancision(
    std::pair<Estado, Simbolo> celda_actual) const {
  if (transiciones_.find(celda_actual) != transiciones_.end()) {
    // hemos encontrado la transición
    return true;
  }
  return false;
}

/**
 * @brief Sobrecarga operador << para mostrar las transiciones
 *
 * @param os
 * @param transicion transición a mostrar
 * @return std::ostream&
 */
std::ostream& operator<<(std::ostream& os, const Transicion& transiciones) {
  for (const auto& transicion : transiciones.GetTransiciones()) {
    os << '(' << transicion.first.first.GetIdentificador() << ", "
       << transicion.first.second << ") -> " << '('
       << transicion.second.estado_siguiente_.GetIdentificador() << ", "
       << transicion.second.simbolo_escritura_ << ", "
       << transicion.second.movimiento_cabeza_ << ')' << std::endl;
  }
  return os;
}

/**
 * @brief Sobrecarga operador = para igualar 2 transiciones
 *
 * @param transicion2 transición a igualar
 * @return Transicion
 */
Transicion Transicion::operator=(const Transicion& transicion2) {
  transiciones_ = transicion2.GetTransiciones();
  return *this;
}

/**
 * @brief Sobrecarga operador [] para poder acceder cómodamente a la terna
 *
 * @param celda_actual par de la celda en la que estamos
 * @return TernaTransicion
 */
TernaTransicion Transicion::operator[](
    const std::pair<Estado, Simbolo>& celda_actual) {
  return transiciones_[celda_actual];
}