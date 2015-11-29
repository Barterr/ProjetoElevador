#include <iostream>
#include <string>
#include "indicador.h"

/**
 * Construtor da classe Indicador
 */
Indicador::Indicador(){
  elevador = -1;
  subindo = 0;
  descendo = 0;
  andarElevador = 0;
}

/**
 * Construtor da classe Indicador, que recebe o id do elevador a qual ele se refere
 */
Indicador::Indicador(int id){
  elevador = id;
  subindo = 0;
  descendo = 0;
  andarElevador = 0;
}

/**
 * Seta a direção a qual o elevador está se deslocando
 * @method Indicador::setDir
 * @param  dir               direção do elevador (SUBINDO, DESCENDO ou IDLE)
 */
void Indicador::setDir(std::string dir){
  if (dir == "SUBINDO") {
    subindo = 1;
    descendo = 0;
  } else if (dir == "DESCENDO") {
    subindo = 0;
    descendo = 1;
  } else if (dir == "IDLE") {
    subindo = 0;
    descendo = 0;
  } else {
    subindo = 0;
    descendo = 0;
  }
  return;
}

/**
 * Seta o andar a ser mostrado no indicador
 * @method Indicador::setAndar
 * @param  andar               número do andar
 */
void Indicador::setAndar(int andar){
  andarElevador = andar;
  return;
}
