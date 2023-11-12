#include "Cinta.h"

/**
 * @brief Constructor por defecto que genera la cinta con símbolos blanco
 *
 */
Cinta::Cinta() {
  for (int i{0}; i < 2; ++i) {
    cinta_.emplace_back(blanco);
  }
  cabeza_ = &cinta_.front();
  alfabeto_cinta_.InsertarSimbolo(blanco);
}

/**
 * @brief Constructor por parámetros que genera la cinta a partir de un fichero
 *
 * @param nombre_fichero nombre del fichero de entrada
 */
Cinta::Cinta(const std::string& nombre_fichero) {
  std::ifstream fichero_entrada{nombre_fichero, std::ios::in};
  std::string cadena;
  fichero_entrada >> cadena;
  // Leemos los símbolos de la cadena y los introducimos en la cinta y establecemos los símbolos del alfabeto de cinta
  for (size_t i{0}; i < cadena.size(); ++i) {
    alfabeto_cinta_.InsertarSimbolo(Simbolo(cadena[i]));
    cinta_.emplace_back(Simbolo(cadena[i]));
  }
  // Añadimos al alfabeto de cinta el símbolo blanco
  alfabeto_cinta_.InsertarSimbolo(blanco);
  // decimos que la cabeza apunta al primer símbolo de la izquierda actual
  cabeza_ = &cinta_.front();
  // Introducimos dos símbolos blancos al principio y al final de la cinta
  for (int j{0}; j < 4; ++j) {
    (j < 2) ? cinta_.emplace_front(blanco) : cinta_.emplace_back(blanco);
  }
  fichero_entrada.close();
}

/**
 * @brief Constructor que contruye la cinta a partir de una cadena
 * 
 * @param cadena cadena que forma la cinta
 */
Cinta::Cinta(const Cadena& cadena) {
  // Leemos los símbolos de la cadena y los introducimos en la cinta y establecemos los símbolos del alfabeto de cinta
  for (const auto& simbolo : cadena.GetCadena()) {
    alfabeto_cinta_.InsertarSimbolo(Simbolo(simbolo));
    cinta_.emplace_back(simbolo);
  }
  // Añadimos al alfabeto de cinta el símbolo blanco
  alfabeto_cinta_.InsertarSimbolo(blanco);
  // decimos que la cabeza apunta al primer símbolo de la izquierda actual
  cabeza_ = &cinta_.front();
  // Introducimos dos símbolos blancos al principio y al final de la cinta
  for (int j{0}; j < 4; ++j) {
    (j < 2) ? cinta_.emplace_front(blanco) : cinta_.emplace_back(blanco);
  }
}

/**
 * @brief Constructor de copia
 * 
 * @param cinta cinta de la que queremos construir la cinta actual
 */
Cinta::Cinta(const Cinta& cinta) {
  *this = cinta;
}

/**
 * @brief Método que permite mover hacia la izquierda la cabeza
 * 
 */
void Cinta::MoverALaIzquierda() {
  --cabeza_;
}

/**
 * @brief Método que permite mover a la derecha la cabeza
 * 
 */
void Cinta::MoverALaDerecha() {
  ++cabeza_;
}

/**
 * @brief Método que permite agregar un símbolo
 * 
 * @param simbolo símbolo que queremos agregar
 * @return Cinta 
 */
Cinta Cinta::AgregarSimbolo(const Simbolo& simbolo) {
  cinta_.emplace_back(simbolo);
  return *this;
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
Cinta Cinta::operator=(const Cinta& cinta2) {
  cinta_ = cinta2.GetCinta();
  return *this;
}
