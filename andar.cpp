#include "andar.h"
#include <array>

void Andar::Andar(){

}

Porta Andar::getPorta(int idElevador){
  if (idElevador<sizeof(portas))
    return  portas[idElevador];
  else
    return NULL;
}

Indicador Andar::getIndicador(int idElevador){
  if (idElevador<sizeof(indicadores))
    return indicadores[idElevador];
    else
    return NULL
}
Botao Andar::getBotaoSubir(){
  return botaoSubir
}
Botao Andar::getBotaoDescer(){
  return botaoDescer
}
