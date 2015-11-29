#include "porta.h"

Porta::Porta(){
  aberta=0;
  sensor=0;
}
bool Porta::estaAberta(){
  return aberta;
}
bool Porta::getSensor(){
  return sensor;
}
void Porta::setSensor(bool a){
  sensor = a;
}
void Porta::abrir(){
  aberta = 1;
}
void Porta::fechar(){
  if (!sensor) {
    aberta = 0;
  }
}
