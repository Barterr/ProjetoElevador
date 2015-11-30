#ifndef ELEVADOR_H
#define ELEVADOR_H

class Elevador {
public:
  Botao botoesPainel [PISOMAX];
  bool subindo;
  bool descendo;
  bool emMovimento;
  bool flagParar;
  bool flagOcupado;
  int andar;
  Indicador indicador;
  Porta porta;
  Botao abrePorta;
  Botao fechaPorta;
public:
	Elevador();
	Elevador(int id);
  void mover();
  int getAndar();
  int getFlagParar();
  bool getSubindo();
  bool getDescendo();
  bool getEmMovimento();
  void setSubindo(bool);
  void setDescendo(bool);
  void setEmMovimento(bool);
  void setFlagParar(int);
  Porta* getPorta();
  Indicador* getIndicador();
  int getBotoesApertados();
  Botao* getBotaoAbre();
  Botao* getBotaoFecha();
  Botao* getBotaoPainel(int);
};
#endif
