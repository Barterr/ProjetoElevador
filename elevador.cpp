#include <chrono>
#include <thread>
#include "elevador.h"

Botao botoes [PISOMAX];
bool subindo;
bool descendo;
bool emMovimento;
int andar;
Indicador indicador;
Porta porta;
Botao abrePorta;
Botao fechaPorta;

Elevador::Elevador(){
  andar = 0;
  emMovimento = 0;
  descendo = 0;
  subindo = 0;
}

Elevador::Elevador(int id){
  andar = 0;
  emMovimento = 0;
  descendo = 0;
  subindo = 0;
  Indicador indicador(id);
}

void Elevador::subir(){
  descendo = 0;
  subindo = 1;
  emMovimento = 1;
  std::this_thread::sleep_for(std::chrono::milliseconds(3*1000));

  descendo = 0;
  subindo = 0;
  emMovimento = 0;
}

void Elevador::descer(){
  descendo = 1;
  subindo = 0;
  emMovimento = 1;
  std::this_thread::sleep_for(std::chrono::milliseconds(3*1000));

  descendo = 0;
  subindo = 0;
  emMovimento = 0;
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

Indicador Elevador::getIndicador(){
  return indicador;
}

int Elevador::getBotoesApertados(){

}
