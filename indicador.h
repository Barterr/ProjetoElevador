#ifndef INDICADOR_H
#define INDICADOR_H

class Indicador {
public:
  int elevador;
  int andarElevador;
  bool subindo;
  bool descendo;
public:
  Indicador();
  Indicador(int id);
  void setDir(std::string dir);
  void setAndar(int andar);
};
#endif
