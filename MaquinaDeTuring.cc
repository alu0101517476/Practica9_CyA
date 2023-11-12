#include "MaquinaDeTuring.h"

/**
 * @brief Constructor que construye a partir de un fichero la MT
 *
 * @param nombre_fichero
 */
MaquinaDeTuring::MaquinaDeTuring(const std::string& nombre_fichero) {
  std::ifstream fichero_entrada{nombre_fichero, std::ios::in};
  // Leemos el numero de estados y el id del estado inicial
  std::string estado_inicial, estado_aceptacion, numero_estados,
      estados_aceptacion, tupla;
  std::getline(fichero_entrada, numero_estados);
  numero_estados_ = std::stoi(numero_estados);
  std::getline(fichero_entrada, estado_inicial);
  // Leemos los estados de aceptación y los metemos tanto en el conjunto de
  // estados de aceptación como el conjunto de estados
  std::getline(fichero_entrada, estados_aceptacion);
  std::stringstream linea{estados_aceptacion};
  while (linea >> estado_aceptacion) {
    if (estado_aceptacion == estado_inicial) {
      Estado estado_inicial_aux{("q" + estado_inicial), true};
      estado_inicial_ = estado_inicial_aux;
    } else {
      Estado estado_inicial_aux{("q" + estado_inicial), false};
      estado_inicial_ = estado_inicial_aux;
    }
    estados_aceptacion_.insert(Estado{"q" + estado_aceptacion, true});
    conjunto_estados_.insert(Estado{"q" + estado_aceptacion, true});
  }
  // Introducimos los estados que nos falta al conjunto de estados
  for (int i{0}; i < numero_estados_; ++i) {
    conjunto_estados_.insert(Estado{"q" + std::to_string(i), false});
  }
  // Leemos el número(n) de tuplas y las n tuplas, introduciendolas como
  // transiciones de la MT
  std::getline(fichero_entrada, tupla);
  numero_tuplas_ = std::stoi(tupla);
  for (int j{0}; j < numero_tuplas_; ++j) {
    std::getline(fichero_entrada, tupla);
    if (tupla.size() != 9) {  // Contamos los espacios
      std::cout
          << "Error, la tupla: " << tupla
          << "\n es incorrecta ya que no tiene los 5 elementos correspondientes"
          << std::endl;
      exit(1);
    }
    std::stringstream linea{tupla};
    std::string aux;
    linea >> aux;
    Estado estado_actual{BuscarEstado(aux)};
    linea >> aux;
    Simbolo simbolo_actual{aux};
    linea >> aux;
    Simbolo simbolo_escritura{aux};
    linea >> aux;
    char movimiento_cabeza{aux[0]};
    linea >> aux;
    Estado estado_siguiente{BuscarEstado(aux)};
    funcion_transicion_.AgregarTransicion(
        std::pair<Estado, Simbolo>(estado_actual, simbolo_actual),
        simbolo_escritura, movimiento_cabeza, estado_siguiente);
  }
  fichero_entrada.close();
}

/**
 * @brief Método que permite buscar y devolver un estado dentro de uno de los
 * conjuntos de estados de la MT
 *
 * @param estado estado que queremos buscar
 * @return Estado
 */
Estado MaquinaDeTuring::BuscarEstado(const std::string& identificador_estado) {
  for (const auto& estado : conjunto_estados_) {
    if (estado.GetIdentificador()[1] == identificador_estado[0]) {
      return estado;
    }
  }
  // No hemos encontrado el estado
  return Estado{};
}

/**
 * @brief Sobrecarga de operador << para poder mostrar la MT por pantalla
 *
 * @param os
 * @param maquina
 * @return std::ostream&
 */
std::ostream& operator<<(std::ostream& os, const MaquinaDeTuring& maquina) {
  os << maquina.numero_estados_ << std::endl;
  os << maquina.estado_inicial_.GetIdentificador()[1] << std::endl;
  for (const auto& estado_aceptacion : maquina.estados_aceptacion_) {
    os << estado_aceptacion.GetIdentificador()[1] << " ";
  }
  os << std::endl << maquina.numero_tuplas_ << std::endl;
  for (const auto& tupla : maquina.funcion_transicion_.GetTransiciones()) {
    os << tupla.first.first.GetIdentificador()[1] << " " << tupla.first.second
       << " " << tupla.second.simbolo_escritura_ << " "
       << tupla.second.movimiento_cabeza_ << " "
       << tupla.second.estado_siguiente_.GetIdentificador()[1] << std::endl;
  }
  return os;
}
