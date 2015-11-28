#include "porta.h"

Porta::Porta(){

}
bool Porta::estaAberta(){
  return aberta;
}
void Porta::getSensor(){
  return sensor;
}
void Porta::abrir(){
  aberta = 1;
  return;
}
void Porta::fechar(){
  aberta = 0;
  return;
}
