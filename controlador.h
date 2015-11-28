#ifndef CONTROLADOR_H
#define CONTROLADOR_H

class Controlador{
private:
  Andar andares[PISOMAX];
  Elevador elevadores[2];
  bool andaresParar[2][PISOMAX]

public:
  Controlador();
  void threadControlador();
  void atualizaIndicadores();
  
}
#endif
