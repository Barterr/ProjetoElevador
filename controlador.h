#ifndef CONTROLADOR_H
#define CONTROLADOR_H

class Controlador{
private:
  Andar andares[PISOMAX];
  Elevador elevadores[NUMELEVADORES];
  bool andaresParar[NUMELEVADORES][PISOMAX]

public:
  Controlador();
  void threadControlador();
  void atualizaIndicadores();

}
#endif
