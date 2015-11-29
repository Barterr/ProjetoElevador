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

void Elevador::subir(){
  if (andar != PISOMAX) {
    descendo = 0;
    subindo = 1;
    emMovimento = 1;
    // std::this_thread::sleep_for(std::chrono::milliseconds(3*1000));
    andar++;
    descendo = 0;
    subindo = 0;
    emMovimento = 0;
  }
  return;
}

void Elevador::descer(){
  if (andar != PISOMAX) {
    descendo = 1;
    subindo = 0;
    emMovimento = 1;
    // std::this_thread::sleep_for(std::chrono::milliseconds(3*1000));
    andar--;
    descendo = 0;
    subindo = 0;
    emMovimento = 0;
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

Porta Elevador::getPorta(){
  return porta;
}

Botao Elevador::getBotaoAbre(){
  return abrePorta;
}

Botao Elevador::getBotaoFecha(){
  return fechaPorta;
}

Indicador Elevador::getIndicador(){
  return indicador;
}

int Elevador::getBotoesApertados(){
  //a implementar
}
