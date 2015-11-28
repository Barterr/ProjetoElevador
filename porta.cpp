#include "porta.h"


  bool aberta;
  bool sensor;
Porta::Porta(){

}
bool Porta::estaAberta(){
  return aberta;
}
void Porta::abrir(){
  aberta = 1;
  return;
}
void Porta::fechar(){
  aberta = 0;
  return;
}
void Porta::getSensor(){

}
