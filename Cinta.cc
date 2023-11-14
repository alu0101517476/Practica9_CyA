// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 9: Implementación de un simulador de Máquinas de Turing
// Autor: Eric y Bermúdez Hernández
// Correo: alu0101517476@ull.edu.es
// Fecha: 14/11/2023
// Archivo Cinta.cc: Implementación de la clase 'Cinta'.
// Contiene todas las implementaciones de la clase 'Cinta'
// 12/11/2023 - Creación (primera versión) del código

#include "Cinta.h"

/**
 * @brief Constructor por defecto que genera la cinta con símbolos blanco
 *
 */
Cinta::Cinta() {
  for (int i{0}; i < 2; ++i) {
    cinta_.emplace_back(blanco);
  }
  cabeza_ = cinta_.begin();
  alfabeto_cinta_.InsertarSimbolo(blanco);
}

/**
 * @brief Constructor por parámetros que genera la cinta a partir de un fichero
 *
 * @param nombre_fichero nombre del fichero de entrada
 */
Cinta::Cinta(const std::string& nombre_fichero) {
  std::ifstream fichero_entrada{nombre_fichero, std::ios::in};
  if (fichero_entrada.fail()) {
    std::cout << "Error, el fichero '" << nombre_fichero
              << "' no se pudo abrir correctamente" << std::endl;
    exit(1);
  }
  std::string cadena;
  fichero_entrada >> cadena;
  // Leemos los símbolos de la cadena y los introducimos en la cinta y
  // establecemos los símbolos del alfabeto de cinta
  for (size_t i{0}; i < cadena.size(); ++i) {
    alfabeto_cinta_.InsertarSimbolo(Simbolo(cadena[i]));
    cinta_.emplace_back(Simbolo(cadena[i]));
  }
  // Añadimos al alfabeto de cinta el símbolo blanco
  alfabeto_cinta_.InsertarSimbolo(blanco);
  // decimos que la cabeza apunta al primer símbolo de la izquierda actual
  cabeza_ = cinta_.begin();
  // Introducimos dos símbolos blancos al principio y al final de la cinta
  cinta_.emplace_front(blanco);
  cinta_.emplace_back(blanco);
  fichero_entrada.close();
}

/**
 * @brief Constructor que contruye la cinta a partir de una cadena
 *
 * @param cadena cadena que forma la cinta
 */
Cinta::Cinta(const Cadena& cadena) {
  // Leemos los símbolos de la cadena y los introducimos en la cinta y
  // establecemos los símbolos del alfabeto de cinta
  for (const auto& simbolo : cadena.GetCadena()) {
    alfabeto_cinta_.InsertarSimbolo(Simbolo(simbolo));
    cinta_.emplace_back(simbolo);
  }
  // Añadimos al alfabeto de cinta el símbolo blanco
  alfabeto_cinta_.InsertarSimbolo(blanco);
  // decimos que la cabeza apunta al primer símbolo de la izquierda actual
  cabeza_ = cinta_.begin();
  // Introducimos dos símbolos blancos al principio y al final de la cinta
  cinta_.emplace_front(blanco);
  cinta_.emplace_back(blanco);
}

/**
 * @brief Constructor de copia
 *
 * @param cinta cinta de la que queremos construir la cinta actual
 */
Cinta::Cinta(Cinta& cinta) { *this = cinta; }

/**
 * @brief Método que permite mover hacia la izquierda la cabeza
 *
 */
void Cinta::MoverCabezaALaIzquierda() {
  if (cabeza_ == cinta_.begin()) {
    cinta_.emplace_front(blanco);
    cinta_.emplace_front(blanco);
    --cabeza_;
  } else {
    --cabeza_;
  }
}

/**
 * @brief Método que permite mover a la derecha la cabeza
 *
 */
void Cinta::MoverCabezaALaDerecha() {
  if (cabeza_ == cinta_.end()) {
    cinta_.emplace_back(blanco);
    cinta_.emplace_back(blanco);
    ++cabeza_;
  } else {
    ++cabeza_;
  }
}

/**
 * @brief Método que permite agregar un símbolo
 *
 * @param simbolo símbolo que queremos agregar
 * @return Cinta
 */
void Cinta::AgregarSimbolo(const Simbolo& simbolo) {
  auto ultima_posicion{std::prev(std::prev(cinta_.end()))};
  cinta_.emplace(ultima_posicion, simbolo);
  alfabeto_cinta_.InsertarSimbolo(simbolo);
}

/**
 * @brief Método que permite agregar un símbolo al alfabeto de cinta
 *
 * @param simbolo símbolo que se quiere agregar
 * @return Alfabeto
 */
Alfabeto Cinta::AgregarSimboloAlfabeto(const Simbolo& simbolo) {
  alfabeto_cinta_.InsertarSimbolo(simbolo);
  return alfabeto_cinta_;
}

/**
 * @brief Método que dice si un símbolo está en el alfabeto de cinta
 *
 * @param simbolo_alfabeto
 * @return true
 * @return false
 */
bool Cinta::EstaEnAlfabeto(const Simbolo& simbolo_alfabeto) const {
  return alfabeto_cinta_.ContieneElSimbolo(simbolo_alfabeto);
}

/**
 * @brief Método que permite reemplazar el símbolo que apunta la cabeza por otro
 *
 * @param simbolo símbolo que vamos a escribir por otro
 * @return Cinta&
 */
Cinta& Cinta::EscribirSimbolo(const Simbolo& simbolo) {
  *cabeza_ = simbolo;
  return *this;
}

/**
 * @brief Método que imprime la cinta mientras se hace la simulación
 *
 * @param estado Estado que vamos a imprimir
 */
void Cinta::ImprimirCintaTraza(const Estado& estado) {
  for (auto it{cinta_.begin()}; it != cinta_.end(); ++it) {
    if (it == cabeza_) {
      std::cout << ' ' << estado.GetIdentificador() << ' ';
    }
    std::cout << *it;
  }
  std::cout << std::endl;
}

/**
 * @brief sobrecarga de operador >> que permite leer una cinta
 *
 * @param is
 * @return * std::istream&
 */
std::istream& Cinta::operator>>(std::istream& is) {
  Cadena cadena_aux;
  is >> cadena_aux;
  Cinta cinta_aux{cadena_aux};
  *this = cinta_aux;
  return is;
}
// Método que permite mostrar una cinta
/**
 * @brief
 *
 * @param os
 * @param cinta
 * @return * std::ostream&
 */
std::ostream& operator<<(std::ostream& os, const Cinta& cinta) {
  os << "...|";
  for (const auto& simbolo : cinta.cinta_) {
    os << simbolo << "|";
  }
  os << "...";
  return os;
}

/**
 * @brief Sobrecarga operador = para igualar 2 cintas
 *
 * @param cinta2 cinta que queremos igualar
 * @return Cinta
 */
Cinta& Cinta::operator=(const Cinta& cinta2) {
  cinta_ = cinta2.cinta_;
  alfabeto_cinta_ = cinta2.GetAlfabetoCinta();
  cabeza_ = std::next(cinta_.begin(), 1);
  return *this;
}
