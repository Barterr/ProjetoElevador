#include <chrono>
#include <thread>
#include "elevador.h"

Elevador::Elevador(){
  andar = 0;
  emMovimento = 0;
  descendo = 0;
  subindo = 0;
}

Elevador::Elevador(int id) : indicador(id) {
  andar = 0;
  emMovimento = 0;
  descendo = 0;
  subindo = 0;
}

void Elevador::mover(){
  while(1) {
    if (emMovimento){
      if (subindo) {
        // std::this_thread::sleep_for(std::chrono::milliseconds(3*1000));
        andar++;
      } else
      if (descendo) {
        // std::this_thread::sleep_for(std::chrono::milliseconds(3*1000));
        andar--;
      }
    } else {
      // std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
  }
  return;
}

int Elevador::getAndar(){
  return andar;
}

bool Elevador::getSubindo(){
  return subindo;
}

bool Elevador::getDescendo(){
  return descendo;
}

bool Elevador::getEmMovimento(){
  return emMovimento;
}

void Elevador::setSubindo(bool i){
  subindo = i;
}

void Elevador::setDescendo(bool i){
  descendo = i;
}

void Elevador::setEmMovimento(bool i){
  emMovimento = i;
}

Porta* Elevador::getPorta(){
  return &porta;
}

Botao* Elevador::getBotaoAbre(){
  return &abrePorta;
}

Botao* Elevador::getBotaoFecha(){
  return &fechaPorta;
}
Botao* Elevador::getBotaoPainel(int i){
  return &botoesPainel[i];
}

Indicador* Elevador::getIndicador(){
  return &indicador;
}

int Elevador::getBotoesApertados(){
  int out = 0;
  for (int i = PISOMAX-1; i >= 0; i--) {
    out <<= 1;
    out += botoesPainel[i].estaPressionado();
  }
  return out;
}
