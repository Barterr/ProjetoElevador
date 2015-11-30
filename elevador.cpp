#include <chrono>
#include <thread>
#include "elevador.h"

Elevador::Elevador() {
  andar       = 0;
  emMovimento = 0;
  descendo    = 0;
  subindo     = 0;
  flagParar   = 0;
  flagOcupado = 0;
}

Elevador::Elevador(int id) : indicador(id) {
  andar       = 0;
  emMovimento = 0;
  descendo    = 0;
  subindo     = 0;
  flagParar   = 0;
  flagOcupado = 0;
}

void Elevador::mover() {
  while (1) {
    if (emMovimento && !porta.estaAberta()) {
      if (subindo) {
        flagParar = 1;
        std::this_thread::sleep_for(std::chrono::milliseconds(1500));
        andar++;
      } else
      if (descendo) {
        flagParar = 1;
        std::this_thread::sleep_for(std::chrono::milliseconds(1500));
        andar--;
      }
    } else {
      std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }
  }
}

int Elevador::getAndar() {
  return andar;
}

int Elevador::getFlagParar() {
  return flagParar;
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

void Elevador::setFlagParar(int valor) {
  flagParar = valor;
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
