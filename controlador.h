#ifndef CONTROLADOR_H
#define CONTROLADOR_H

class Controlador{
private:
  Andar andares[PISOMAX];
  Elevador elevadores[NUMELEVADORES];
  bool andaresParar[NUMELEVADORES][PISOMAX];

public:
  Controlador();
  Elevador* getElevador(int id);
  void threadControlador();
  void atualizaArrays();
  void acionamentos();
  void procedimentosFinais();
};
#endif
