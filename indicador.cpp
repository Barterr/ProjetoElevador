#include <iostream>
#include <string>
#include "indicador.h"

Indicador::Indicador(){
  elevador = NULL;
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

void setDir(string dir){
  switch (dir) {
    case "SUBINDO":
    subindo = 1;
    descendo = 0;
    case "DESCENDO":
    subindo = 0;
    descendo = 1;
    case "PARADO":
    subindo = 0;
    descendo = 0;
    default:
    subindo = 0;
    descendo = 0;
  }
}

void setAndar(int andar){
  andarElevador = andar;
}
