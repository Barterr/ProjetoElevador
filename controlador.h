#ifndef CONTROLADOR_H
#define CONTROLADOR_H

class Controlador{
public:
  Andar andares[PISOMAX];
  Elevador elevadores[NUMELEVADORES];
  bool andaresParar[NUMELEVADORES][PISOMAX];
  bool chamadasSubir[PISOMAX];
  bool chamadasDescer[PISOMAX];

public:
  Controlador();
  Elevador* getElevador(int id);
  void threadControlador();
  void atualizaArrays();
  void atualizarChamadas();
  void atualizarPortas();
  void atenderChamadas();
  void atualizarMovimentos();
  void abrirFecharPorta(int idElevador);
  bool temPendencias(int idElevador);
  int getUltimoDestino(int idElevador);
  int getProximoDestino(int idElevador);
  void procedimentosFinais();
};
#endif
