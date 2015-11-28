#include <iostream>
#include <string>
#include "indicador.h"

Indicador::Indicador(){
  elevador = -1;
  subindo = 0;
  descendo = 0;
  andarElevador = 0;
}

Indicador::Indicador(int id){
  elevador = id;
  subindo = 0;
  descendo = 0;
  andarElevador = 0;
}

void Indicador::setDir(std::string dir){
  if (dir == "SUBINDO") {
    subindo = 1;
    descendo = 0;
  } else if (dir == "DESCENDO") {
    subindo = 0;
    descendo = 1;
  } else if (dir == "PARADO") {
    subindo = 0;
    descendo = 0;
  } else {
    subindo = 0;
    descendo = 0;
  }
  return;
}

void Indicador::setAndar(int andar){
  andarElevador = andar;
  return;
}
