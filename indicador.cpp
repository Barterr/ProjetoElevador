#include "indicador.h"

Indicador::Indicador(){

}
bool Indicador::estaAberta(){
  return aberta;
}
void Indicador::getSensor(){
  return sensor;
}
void Indicador::abrir(){
  aberta = 1;
  return;
}
void Indicador::fechar(){
  aberta = 0;
  return;
}
