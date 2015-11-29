#ifndef CONTROLADOR_H
#define CONTROLADOR_H

class Controlador{
private:
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
  void atenderChamadas();
  void atualizarMovimentos();
  bool temPendencias(int idElevador);
  int getUltimoDestino(int idElevador);
  int getProximoDestino(int idElevador);
  void procedimentosFinais();
};
#endif
