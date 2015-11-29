#include "controlador.h"
#include <iostream>
using namespace std;

Controlador::Controlador() {}

void Controlador::threadControlador() {
  atualizarChamadas();
  atualizaArrays();
}

void Controlador::atualizaArrays() {
  int botoesApertados[NUMELEVADORES];

  for (int i = 0; i < NUMELEVADORES; i++) {
    botoesApertados[i] = elevadores[i].getBotoesApertados();
  }

  for (int i = 0; i < NUMELEVADORES; i++) {
    for (int j = 0; j < PISOMAX; j++) {
      andaresParar[i][j]   = botoesApertados[i] & 0x01;
      botoesApertados[i] >>= 1;
    }
  }

  for (int i = 0; i < PISOMAX; i++) {
    if (chamadasSubir[i]) {
      
    }
  }

}

void Controlador::atualizarChamadas() {
  for (int i = 0; i < PISOMAX; i++) {
    chamadasSubir[i]  = andares[i].getBotaoSubir()->estaPressionado();
    chamadasDescer[i] = andares[i].getBotaoDescer()->estaPressionado();
  }
}



void Controlador::atualizarMovimentos() {
  for (int i = 0; i < NUMELEVADORES; i++) {
    if (temPendencias(i)) {
      int andarAtual     = elevadores[i].getAndar();
      int proximoDestino = getProximoDestino(i);
      int ultimoDestino  = getUltimoDestino(i);

      if (elevadores[i].getEmMovimento()) {
        if (elevadores[i].getSubindo()) {
          if (proximoDestino == (andarAtual + 1)) {
            elevadores[i].setEmMovimento(0);

            if (proximoDestino == ultimoDestino) {
              elevadores[i].setSubindo(0);
            }
          }
        }
        else if (elevadores[i].getDescendo()) {
          if (proximoDestino == (andarAtual - 1)) {
            elevadores[i].setEmMovimento(0);

            if (proximoDestino == ultimoDestino) {
              elevadores[i].setDescendo(0);
            }
          }
        }
      }
      else {
        if (!elevadores[i].getSubindo() && !elevadores[i].getDescendo()) {
          elevadores[i].setDescendo(proximoDestino < andarAtual);
          elevadores[i].setSubindo(proximoDestino > andarAtual);
        }
      }
    }
    elevadores[i].setEmMovimento(0);
    elevadores[i].setSubindo(0);
    elevadores[i].setDescendo(0);
  }
}

bool Controlador::temPendencias(int idElevador) {
  for (int i = 0; i < PISOMAX; i++) {
    if (andaresParar[idElevador][i]) {
      return 1;
    }
  }
  return 0;
}

int Controlador::getUltimoDestino(int idElevador) {
  int andarDestino = elevadores[idElevador].getAndar();

  if (elevadores[idElevador].getDescendo()) {
    for (int i = PISOMAX; i >= 0; i--) {
      if (andarandaresParar[i]) {
        andarDestino = i;
      }
    }
  }

  if (elevadores[idElevador].getSubindo()) {
    for (int i = 0; i < PISOMAX; i++) {
      if (andarandaresParar[i]) {
        andarDestino = i;
      }
    }
  }
  return andarDestino;
}

int Controlador::getProximoDestino(int idElevador) {
  if (elevadores[idElevador].getDescendo()) {
    for (int i = PISOMAX; i >= 0; i--) {
      if (andarandaresParar[i]) {
        return i;
      }
    }
  }
  else {
    for (int i = 0; i < PISOMAX; i++) {
      if (andarandaresParar[i]) {
        return i;
      }
    }
  }
}

void       Controlador::procedimentosFinais() {}

Elevador * Controlador::getElevador(int id) {
  return &elevadores[id];
}
