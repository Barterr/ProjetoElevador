#include "andar.h"

Andar::Andar(){
  for (int i = 0; i < NUMELEVADORES; i++) {
    indicadores[i] = Indicador(i);
  }
}

Porta* Andar::getPorta(int idElevador){
  if (idElevador < NUMELEVADORES)
    return &portas[idElevador];
  else
    return NULL;
}

Indicador* Andar::getIndicador(int idElevador){
  if (idElevador < NUMELEVADORES)
    return &indicadores[idElevador];
  else
    return NULL;
}
Botao Andar::getBotaoSubir(){
  return botaoSubir;
}
Botao Andar::getBotaoDescer(){
  return botaoDescer;
}
