#ifndef INDICADOR_H
#define INDICADOR_H


class Indicador {
private:
  int elevador;
  int andarElevador;
  bool subindo;
  bool descendo;
public:
  Indicador();
  void setDir(string dir);
  void setAndar(int andar);
};
#endif
