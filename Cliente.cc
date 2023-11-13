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
  // ***-> HACER QUE DESPUÉS DE CONSTRUIR LA MT, SE PREGUNTE AL USUARIO SI SE QUIERE MOSTRAR LA MT
  MaquinaDeTuring maquina{"input.tm", "input.tape"};
  maquina.EsAceptada();
  return 0; 
}