#include "MaquinaDeTuring.h"

/**
 * @brief Constructor que construye a partir de un fichero la MT
 *
 * @param nombre_fichero
 */
MaquinaDeTuring::MaquinaDeTuring(const std::string& nombre_fichero_mt, const std::string& nombre_fichero_cinta) {
  std::ifstream fichero_entrada{nombre_fichero_mt, std::ios::in};
  // Iniciamos la cinta de la máquina
  Cinta cinta_aux{nombre_fichero_cinta};
  cinta_ = cinta_aux;
  // Leemos el numero de estados y el id del estado inicial
  std::string estado_inicial, estado_aceptacion, numero_estados,
      estados_aceptacion, tupla;
  std::getline(fichero_entrada, numero_estados);
  numero_estados_ = std::stoi(numero_estados);
  // COMPROBACIÓN NUMERO DE ESTADOS CORRECTOS
  if (numero_estados_ == 0) {
    std::cout << "Error, el número de estados no puede ser 0" << std::endl;
    exit(1);
  }
  std::getline(fichero_entrada, estado_inicial);
  // COMPROBACIÓN ESTADO INCIAL CORRECTO
  if (estado_inicial > numero_estados) {
    std::cout << "Error, el estado " << estado_inicial << " no existe en la MT" << std::endl;
    exit(1);
  }
  // Leemos los estados de aceptación y los metemos tanto en el conjunto de
  // estados de aceptación como el conjunto de estados
  std::getline(fichero_entrada, estados_aceptacion);
  std::stringstream linea{estados_aceptacion};
  while (linea >> estado_aceptacion) {
    // COMPROBACIÓN ESTADO DE ACEPTACIÓN CORRECTO
    if (estado_aceptacion > numero_estados) {
      std::cout << "Error, el estado " << estado_aceptacion << " no existe en la MT" << std::endl;
      exit(1);
    }
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
  for (int j{1}; j <= numero_tuplas_; ++j) {
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
    // COMPROBACIÓN EL ESTADO ACTUAL EXISTE EN LA MT
    if (aux > numero_estados) {
      std::cout << "Error, el estado " << estado_actual << " no existe en la MT" << std::endl;
      exit(1);
    }
    linea >> aux;
    Simbolo simbolo_actual{aux};
    // COMPROBACIÓN SÍMBOLO ACTUAL ESTÁ EN EL ALFABETO DE CINTA
    if (!cinta_.EstaEnAlfabeto(simbolo_actual)) {
      cinta_.AgregarSimboloAlfabeto(simbolo_actual);
    }
    linea >> aux;
    Simbolo simbolo_escritura{aux};
    // COMPROBACIÓN SÍMBOLO ESCRITURA ESTÁ EN EL ALFABETO DE CINTA
    if (!cinta_.EstaEnAlfabeto(simbolo_escritura)) {
      cinta_.AgregarSimboloAlfabeto(simbolo_escritura);
    }
    linea >> aux;
    char movimiento_cabeza{aux[0]};
    // COMPROBACIÓN MOVIMIENTO CABEZA CORRECTO
    if (!funcion_transicion_.EsMovimientoCorrecto(movimiento_cabeza)) {
      std::cout << "Error, el movimiento " << movimiento_cabeza << " no es correcto"
                << std::endl;
      exit(1);
    }
    linea >> aux;
    Estado estado_siguiente{BuscarEstado(aux)};
    // COMPROBACIÓN EL ESTADO SIGUIENTE EXISTE EN LA MT
    if (aux > numero_estados) {
      std::cout << "Error, el estado " << estado_siguiente << " no existe en la MT" << std::endl;
      exit(1);
    }
    funcion_transicion_.AgregarTransicion(
        std::pair<Estado, Simbolo>(estado_actual, simbolo_actual),
        simbolo_escritura, movimiento_cabeza, estado_siguiente);
  }
  // COMPROBACIÓN 0 TRANSICIONES
  if (funcion_transicion_.Size() == 0) {
    std::cout << "Error, el número de transiciones es 0, la MT no puede "
                 "realizar ningún cómputo"
              << std::endl;
    exit(1);
  }
  fichero_entrada.close();
}

/**
 * @brief Constructor de copia
 * 
 * @param maquina2 
 */
MaquinaDeTuring::MaquinaDeTuring(const MaquinaDeTuring& maquina2) {
  *this = maquina2;
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
 * @brief Método que permite simular el funcionamiento de una MT
 *
 * @return true
 * @return false
 */
bool MaquinaDeTuring::SimulacionMT() { 
  // Inicializamos el par con el estado inicial y el símbolo en el que está la cabeza
  std::pair<Estado, Simbolo> par{estado_inicial_, cinta_.SimboloActual()};
  while (funcion_transicion_.ExisteTrancision(par)) {
    // Mostramos la traza
    cinta_.ImprimirCintaTraza(par.first);
    // Reemplazamos el símbolo por el que nos piden
    cinta_.EscribirSimbolo(funcion_transicion_[par].simbolo_escritura_);
    // Movemos la cabeza de sitio
    if (funcion_transicion_[par].movimiento_cabeza_ == 'L') {
      cinta_.MoverCabezaALaIzquierda();
    } else if (funcion_transicion_[par].movimiento_cabeza_ == 'R') {
      cinta_.MoverCabezaALaDerecha();
    }
    // Actualizamos el par que estamos inspeccionando
    std::pair<Estado, Simbolo> par_aux{funcion_transicion_[par].estado_siguiente_, cinta_.SimboloActual()};
    par = par_aux;
  } 
  cinta_.ImprimirCintaTraza(par.first);
  return (par.first.GetAceptado()) ? true : false;
}

// Método que dice si la cadena es aceptada o no
/**
 * @brief 
 * 
 */
void MaquinaDeTuring::EsAceptada() {
  (SimulacionMT()) ? std::cout << "Cadena ACEPTADA" << std::endl : std::cout << "Cadena RECHAZADA" << std::endl; 
}

/**
 * @brief Sobrecarga operador = para igualar 2 máquinas de turing
 * 
 * @param maquina2 segunda máquina
 * @return MaquinaDeTuring& 
 */
MaquinaDeTuring& MaquinaDeTuring::operator=(const MaquinaDeTuring& maquina2) {
  numero_estados_ = maquina2.numero_estados_;
  numero_tuplas_ = maquina2.numero_tuplas_;
  conjunto_estados_ = maquina2.conjunto_estados_;
  cinta_ = maquina2.cinta_;
  estado_inicial_ = maquina2.estado_inicial_;
  estados_aceptacion_ = maquina2.estados_aceptacion_;
  funcion_transicion_ = maquina2.funcion_transicion_;
  return *this;
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
