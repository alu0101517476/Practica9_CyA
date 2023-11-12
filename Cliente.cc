#include <iostream>
#include <list>

#include <iostream>
#include <list>
#include <fstream>

#include "Alfabeto.h"
#include "Simbolo.h"
#include "Cadena.h"
#include "Cinta.h"
#include "Transicion.h"
#include "MaquinaDeTuring.h"
#include "Estado.h"

int main() {
  MaquinaDeTuring maquina{"input.tm"};
  std::cout << maquina << std::endl;
  return 0;
}