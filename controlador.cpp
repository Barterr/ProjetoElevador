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
  // for (int i = 0; i < NUMELEVADORES; i++) {
  //   std::this_thread::sleep_for(std::chrono::milliseconds(500));
  //   std::thread threadElevador (elevadores[i].mover, &elevadores[i]);
  // }
  while (1) {
    atualizarPortas();
    atualizarChamadas();
    atualizarArrays();
    atenderChamadas();
    atualizarMovimentos();
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
    if (chamadasSubir[i] && !andares[i].getBotaoSubir()->getAtendido()) {
      int distancia[NUMELEVADORES];
      int responsavel = -1;

      // calcula as distancias dos elevadores até as chamadas
      for (int j = 0; j < NUMELEVADORES; j++) {
        if (!elevadores[j].getDescendo()) {
          int ultimoDestino = getUltimoDestino(j);
          int andarAtual    = elevadores[j].getAndar();
          distancia[j] = abs(ultimoDestino - andarAtual) + abs(ultimoDestino - i);
        }
        else {
          distancia[j] = -1;
        }
      }

      if (distancia[0] != -1) {
        responsavel = 0;
      }

      if (NUMELEVADORES > 1) {
        for (int j = 1; j < NUMELEVADORES; j++) {
          if (distancia[j] != -1) {
            if (distancia[j] < distancia[responsavel]) {
              responsavel = j;
            }
          }
        }
      }
      andaresParar[responsavel][i] = 1;
      andares[i].getBotaoSubir()->setAtendido(1);
    }

    if (chamadasDescer[i] && !andares[i].getBotaoDescer()->getAtendido()) {
      int distancia[NUMELEVADORES];
      int responsavel = -1;

      // calcula as distancias dos elevadores até as chamadas
      for (int j = 0; j < NUMELEVADORES; j++) {
        if (!elevadores[j].getSubindo()) {
          int ultimoDestino = getUltimoDestino(j);
          int andarAtual    = elevadores[j].getAndar();
          distancia[j] = abs(ultimoDestino - andarAtual) + abs(ultimoDestino - i);
        }
        else {
          distancia[j] = -1;
        }
      }

      if (distancia[0] != -1) {
        responsavel = 0;
      }

      if (NUMELEVADORES > 1) {
        for (int j = 1; j < NUMELEVADORES; j++) {
          if (distancia[j] != -1) {
            if (distancia[j] < distancia[responsavel]) {
              responsavel = j;
            }
          }
        }
      }

      andaresParar[responsavel][i] = 1;
      andares[i].getBotaoDescer()->setAtendido(1);

      // std::cout << andaresParar[responsavel][i] << std::endl;
    }
  }
}

void Controlador::atualizarChamadas() {
  for (int i = 0; i < PISOMAX; i++) {
    if (!andares[i].getBotaoSubir()->getAtendido()) {
      chamadasSubir[i]  = andares[i].getBotaoSubir()->estaPressionado();
    }
    if (!andares[i].getBotaoDescer()->getAtendido()) {
      chamadasDescer[i] = andares[i].getBotaoDescer()->estaPressionado();
    }

    if (chamadasSubir[i] || chamadasDescer[i]) {
      for (int j = 0; j < NUMELEVADORES; j++) {
        if (elevadores[j].getSubindo()
            && (andaresParar[j][i] == 1)
            && (elevadores[j].getAndar() < i)) {
          chamadasSubir[i] = 0;
        }
        else if (elevadores[j].getDescendo()
                 && (andaresParar[j][i] == 1)
                 && (elevadores[j].getAndar() > i)) {
          chamadasDescer[i] = 0;
        }
      }
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
