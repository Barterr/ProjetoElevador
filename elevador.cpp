#include <chrono>
#include <thread>
#include "elevador.h"

Elevador::Elevador() {
  andar       = 0;
  emMovimento = 0;
  descendo    = 0;
  subindo     = 0;
  flagParar   = 0;
  flagFecharPorta = 0;
  flagAbrirPorta = 0;
}

Elevador::Elevador(int id) : indicador(id) {
  andar       = 0;
  emMovimento = 0;
  descendo    = 0;
  subindo     = 0;
  flagParar   = 0;
  flagFecharPorta = 0;
  flagAbrirPorta = 0;
}

void Elevador::mover() {
  while (1) {
    if (emMovimento && !porta.estaAberta()) {
      if (subindo) {
        flagParar = 1;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        andar++;
      } else
      if (descendo) {
        flagParar = 1;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        andar--;
      }
    } else {
      std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }
  }
}

void Elevador::threadPortas() {
  while(1){
    if (flagAbrirPorta) {
      porta.abrir();
      flagAbrirPorta = 0;
    }
    else if (flagFecharPorta) {
      porta.fechar();
      emMovimento = 1;
      flagFecharPorta = 0;
    }
  }
  std::this_thread::sleep_for(std::chrono::milliseconds(50));
}

int Elevador::getAndar() {
  return andar;
}

bool Elevador::getFlagParar() {
  return flagParar;
}
bool Elevador::getFlagAbrirPorta() {
  return flagAbrirPorta;
}
bool Elevador::getFlagFecharPorta() {
  return flagFecharPorta;
}

bool Elevador::getSubindo() {
  return subindo;
}

bool Elevador::getDescendo() {
  return descendo;
}

bool Elevador::getEmMovimento() {
  return emMovimento;
}

void Elevador::setSubindo(bool valor) {
  subindo = valor;
}

void Elevador::setDescendo(bool valor) {
  descendo = valor;
}

void Elevador::setEmMovimento(bool valor) {
  emMovimento = valor;
}

void Elevador::setFlagParar(bool valor) {
  flagParar = valor;
}

void Elevador::setFlagAbrirPorta(bool valor) {
  flagAbrirPorta = valor;
}

void Elevador::setFlagFecharPorta(bool valor) {
  flagFecharPorta = valor;
}

Porta * Elevador::getPorta() {
  return &porta;
}

Botao * Elevador::getBotaoAbre() {
  return &abrePorta;
}

Botao * Elevador::getBotaoFecha() {
  return &fechaPorta;
}

Botao * Elevador::getBotaoPainel(int i) {
  return &botoesPainel[i];
}

Indicador * Elevador::getIndicador() {
  return &indicador;
}

int Elevador::getBotoesApertados() {
  int out = 0;

  for (int i = PISOMAX - 1; i >= 0; i--) {
    out <<= 1;
    out  += botoesPainel[i].estaPressionado();
  }
  return out;
}
