#include "controlador.h"

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
  for (int i = 0; i < NUMELEVADORES; i++) {
    elevadores[i].criarThread();
  }

  while (1) {
    atualizarChamadas();
    atualizaArrays();
    atenderChamadas();
    atualizarMovimentos();
    std::this_thread::sleep_for(std::chrono::milliseconds(5));
  }
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
}

void Controlador::atenderChamadas() {
  for (int i = 0; i < PISOMAX; i++) {
    if (chamadasSubir[i]) {
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
    }

    if (chamadasDescer[i]) {
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
    }
  }
}

void Controlador::atualizarChamadas() {
  for (int i = 0; i < PISOMAX; i++) {
    chamadasSubir[i]  = andares[i].getBotaoSubir()->estaPressionado();
    chamadasDescer[i] = andares[i].getBotaoDescer()->estaPressionado();

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
      if (andaresParar[i]) {
        andarDestino = i;
      }
    }
  }

  if (elevadores[idElevador].getSubindo()) {
    for (int i = 0; i < PISOMAX; i++) {
      if (andaresParar[i]) {
        andarDestino = i;
      }
    }
  }
  return andarDestino;
}

int Controlador::getProximoDestino(int idElevador) {
  if (elevadores[idElevador].getDescendo()) {
    for (int i = PISOMAX; i >= 0; i--) {
      if (andaresParar[i]) {
        return i;
      }
    }
  }
  else {
    for (int i = 0; i < PISOMAX; i++) {
      if (andaresParar[i]) {
        return i;
      }
    }
  }
  return -1;
}

void       Controlador::procedimentosFinais() {}

Elevador * Controlador::getElevador(int id) {
  return &elevadores[id];
}
