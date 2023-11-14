// Universidad de La Laguna
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Práctica 9: Implementación de un simulador de Máquinas de Turing
// Autor: Eric y Bermúdez Hernández
// Correo: alu0101517476@ull.edu.es
// Fecha: 14/11/2023
// Archivo Cliente.cc: Programa cliente que pone a prueba el funcionamiento de
// las clase 'MaquinaDeTuring' y sus relacionadas.
// 12/11/2023 - Creación (primera versión) del código

#include <fstream>
#include <iostream>
#include <list>

#include "Alfabeto.h"
#include "Cadena.h"
#include "Cinta.h"
#include "Estado.h"
#include "MaquinaDeTuring.h"
#include "Simbolo.h"
#include "Transicion.h"

void Ayuda() {
  std::cout
      << "Este programa genera a partir de dos ficheros una Máquina de Turing "
         "y su cinta correspondiente.\nLa MT se genera a partir del fichero "
         "con extensión '.tm' y la cinta con el fichero con extensión "
         "'.tape'.\nUna vez estos dos objetos, se comienza a simular el "
         "funcionamiento de la MT mostrando la traza en cada paso de la "
         "simulación,\ndiciendo finalmente si la cadena es acpetada"
      << std::endl;
}

int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::cout << "Número de parámetros incorrectos.\nEl modo de empleo es el "
                 "siguiente: ./p09_simulador_MT  input.tm output.tape"
                 "\nPruebe './p09_simulador_MT --help' para más "
                 "información."
              << std::endl;
    return 1;
  }
  std::string nombre_fichero_entrada_mt{argv[1]};
  if (nombre_fichero_entrada_mt == "--help") {
    Ayuda();
    return 0;
  }
  std::string nombre_fichero_entrada_cinta{argv[2]};
  if (nombre_fichero_entrada_mt.substr(nombre_fichero_entrada_mt.size() - 3) !=
          ".tm" ||
      nombre_fichero_entrada_cinta.size() < 3) {
    std::cout << "Error, el fichero '" << nombre_fichero_entrada_mt
              << "' no tiene extensión '.tm'" << std::endl;
    return 1;
  } else if (nombre_fichero_entrada_cinta.substr(
                 nombre_fichero_entrada_cinta.size() - 5) != ".tape" ||
             nombre_fichero_entrada_cinta.size() < 5) {
    std::cout << "Error, el fichero '" << nombre_fichero_entrada_cinta
              << "' no tiene extensión '.tape'" << std::endl;
    return 1;
  }
  MaquinaDeTuring maquina{nombre_fichero_entrada_mt,
                          nombre_fichero_entrada_cinta};
  char mostrar;
  std::cout << "¿Desea mostrar la Máquina de Turing construida? (S/N)";
  std::cin >> mostrar;
  if (mostrar == 'S' || mostrar == 's') {
    std::cout << "--- Máquina de Turing ---" << std::endl;
    std::cout << maquina;
    std::cout << "-----------------" << std::endl;
  }
  maquina.EsAceptada();
  return 0;
}