#include "controlador.h"
#include <iostream>
#include <thread>


Controlador::Controlador() {
  for (int i = 0; i < PISOMAX; i++) {
    chamadasDescer[i] = 0;
    chamadasSubir[i]  = 0;

    for (int j = 0; j < NUMELEVADORES; j++) {
      andaresParar[j][i] = 0;
    }
  }

  for (int j = 0; j < NUMELEVADORES; j++) {
    elevadores[j] = Elevador(j);
  }
}

void Controlador::threadControlador() {
  while (1) {
    atualizarPortas();
    atualizarArrays();
    atualizarChamadas();
    atenderChamadas();
    atualizarMovimentos();
    atualizarIndicadores();
    std::this_thread::sleep_for(std::chrono::milliseconds(5));
  }
}

void Controlador::atualizarArrays() {
  int botoesApertados[NUMELEVADORES];

  for (int i = 0; i < NUMELEVADORES; i++) {
    botoesApertados[i] = elevadores[i].getBotoesApertados();
  }

  for (int i = 0; i < NUMELEVADORES; i++) {
    for (int j = 0; j < PISOMAX; j++) {
      andaresParar[i][j]   = ((botoesApertados[i] & 0x01) | andaresParar[i][j]);
      botoesApertados[i] >>= 1;
    }
  }
}

void Controlador::atenderChamadas() {
  for (int i = 0; i < PISOMAX; i++) {
    int distancia[NUMELEVADORES];
    int responsavel = 0;

    if (chamadasSubir[i] && !andares[i].getBotaoSubir()->getAtendido()) {
      // calcula as distancias dos elevadores até as chamadas
      for (int j = 0; j < NUMELEVADORES; j++) {
        int ultimoDestino = getUltimoDestino(j);
        int andarAtual    = elevadores[j].getAndar();
        if (!elevadores[j].getDescendo()) { //aka elevador subindo ou parado
          distancia[j] = abs(andarAtual - i);
        }
        else {
          distancia[j] = abs(ultimoDestino - andarAtual) + abs(ultimoDestino - i);
        }
      }

      for (int j = 0; j < NUMELEVADORES; j++) {
        if (distancia[j] <= distancia[responsavel]) {
          responsavel = j;
        }
      }
      andaresParar[responsavel][i] = 1;
      andares[i].getBotaoSubir()->setAtendido(1);
    }
  }
  for (int i = 0; i < PISOMAX; i++) {
    int distancia[NUMELEVADORES];
    int responsavel = 0;

    if (chamadasDescer[i] && !andares[i].getBotaoDescer()->getAtendido()) {
      // calcula as distancias dos elevadores até as chamadas
      for (int j = 0; j < NUMELEVADORES; j++) {
        int ultimoDestino = getUltimoDestino(j);
        int andarAtual    = elevadores[j].getAndar();
        if (!elevadores[j].getSubindo()) { //aka elevador descendo ou parado
          distancia[j] = abs(andarAtual - i);
        }
        else {
          distancia[j] = abs(ultimoDestino - andarAtual) + abs(ultimoDestino - i);
        }
      }
      for (int j = 0; j < NUMELEVADORES; j++) {
        if (distancia[j] < distancia[responsavel]) {
          responsavel = j;
        }
      }
      andaresParar[responsavel][i] = 1;
      andares[i].getBotaoDescer()->setAtendido(1);
    }
  }
}

void Controlador::atualizarChamadas() {
  for (int i = 0; i < PISOMAX; i++) {
    chamadasSubir[i] = 0;
    chamadasDescer[i] = 0;
    if (!andares[i].getBotaoSubir()->getAtendido() && andares[i].getBotaoSubir()->estaPressionado()) {
      chamadasSubir[i]  = 1;
    }
    if (!andares[i].getBotaoDescer()->getAtendido() && andares[i].getBotaoDescer()->estaPressionado()) {
      chamadasDescer[i] = 1;
    }
  }
}

void Controlador::atualizarMovimentos() {
  for (int i = 0; i < NUMELEVADORES; i++) {
    int andarAtual     = elevadores[i].getAndar();
    int proximoDestino = getProximoDestino(i);
    int ultimoDestino  = getUltimoDestino(i);

    if (elevadores[i].getFlagParar()) {
      if (temPendencias(i)) {
        if (elevadores[i].getEmMovimento()) {
          if (elevadores[i].getSubindo()) {
            if (proximoDestino == (andarAtual + 1)) {
              elevadores[i].setEmMovimento(0);
              elevadores[i].setFlagParar(0);
            }
          }
          else if (elevadores[i].getDescendo()) {
            if (proximoDestino == (andarAtual - 1)) {
              elevadores[i].setEmMovimento(0);
              elevadores[i].setFlagParar(0);
            }
          }
        }
      }
    }
    else if (!elevadores[i].getFlagParar() && elevadores[i].getPorta()->estaAberta() && temPendencias(i)) {
      elevadores[i].setDescendo(proximoDestino < andarAtual);
      elevadores[i].setSubindo(proximoDestino > andarAtual);
      elevadores[i].setFlagFecharPorta(1);
    }
    else if (!elevadores[i].getPorta()->estaAberta() && elevadores[i].getEmMovimento()) {
      elevadores[i].setDescendo(proximoDestino < andarAtual);
      elevadores[i].setSubindo(proximoDestino > andarAtual);
    }
    else if (!temPendencias(i) && !elevadores[i].getEmMovimento()) {
      elevadores[i].setSubindo(0);
      elevadores[i].setDescendo(0);
    }
  }
}

void Controlador::atualizarPortas() {
  for (int i = 0; i < NUMELEVADORES; i++) {
    if (!elevadores[i].getEmMovimento()) {
      if (elevadores[i].getAndar() == getProximoDestino(i)) {
        int andar = elevadores[i].getAndar();
        andaresParar[i][andar] = 0;
        elevadores[i].getBotaoPainel(andar)->desapertar();
        if (elevadores[i].getSubindo()) {
          andares[andar].getBotaoSubir()->desapertar();
        }
        else if (elevadores[i].getDescendo()) {
          andares[andar].getBotaoDescer()->desapertar();
        }
        elevadores[i].setFlagAbrirPorta(1);
      }
    }
  }
}

void Controlador::atualizarIndicadores() {
  for (int i = 0; i < NUMELEVADORES; i++) {
    bool subindo = elevadores[i].getSubindo();
    bool descendo = elevadores[i].getDescendo();
    int andar = elevadores[i].getAndar();

    elevadores[i].getIndicador()->setDir(subindo?"SUBINDO":(descendo?"DESCENDO":"IDLE"));
    elevadores[i].getIndicador()->setAndar(andar);

    for (int j = 0; j < PISOMAX; j++) {
      andares[j].getIndicador(i)->setDir(subindo?"SUBINDO":(descendo?"DESCENDO":"IDLE"));
      andares[j].getIndicador(i)->setAndar(andar);
    }
  }
}

bool Controlador::temPendencias(int idElevador) {
  bool out = 0;
  for (int i = 0; i < PISOMAX; i++) {
    if (andaresParar[idElevador][i]) {
      out = 1;
    }
  }
  return out;
}

int Controlador::getUltimoDestino(int idElevador) {
  int andarDestino = elevadores[idElevador].getAndar();

  if (elevadores[idElevador].getDescendo()) {
    for (int i = elevadores[idElevador].getAndar(); i >= 0; i--) {
      if (andaresParar[idElevador][i]) {
        andarDestino = i;
      }
    }
  }

  if (elevadores[idElevador].getSubindo()) {
    for (int i = elevadores[idElevador].getAndar(); i < PISOMAX; i++) {
      if (andaresParar[idElevador][i]) {
        andarDestino = i;
      }
    }
  }
  return andarDestino;
}

int Controlador::getProximoDestino(int idElevador) {
  int proxDest = elevadores[idElevador].getAndar();

  if (elevadores[idElevador].getDescendo()) {
    for (int i = elevadores[idElevador].getAndar(); i >= 0; i--) {
      if (andaresParar[idElevador][i]) {
        proxDest = i;
        break;
      }
    }
  }
  else if (elevadores[idElevador].getSubindo()){
    for (int i = elevadores[idElevador].getAndar(); i < PISOMAX; i++) {
      if (andaresParar[idElevador][i]) {
        proxDest = i;
        break;
      }
    }
  }
  else {
    for (int i = 0; i < PISOMAX; i++) {
      if (andaresParar[idElevador][i]) {
        proxDest = i;
        break;
      }
    }
  }
  return proxDest;
}

Elevador * Controlador::getElevador(int id) {
  return &elevadores[id];
}
