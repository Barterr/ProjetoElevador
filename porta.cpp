#include "porta.h"

Porta::Porta(){
  aberta=0;
  sensor=0;
}
bool Porta::estaAberta(){
  return aberta;
}
void Porta::getSensor(){
  return sensor;
}
void Porta::setSensor(bool a){
  sensor = a;
  return;
}
void Porta::abrir(){
  aberta = 1;
  return;
}
void Porta::fechar(){
  aberta = 0;
  return;
}
