
#ifndef PORTA_H
#define PORTA_H

class Porta {
private:
  bool aberta;
  bool sensor;
public:
	Porta();
  bool estaAberta();
  bool getSensor();
  bool setSensor();
  void abrir();
  void fechar();
};
#endif
