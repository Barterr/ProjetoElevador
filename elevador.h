#ifndef ELEVADOR_H
#define ELEVADOR_H

class Elevador {
public:
  Botao botoesPainel [PISOMAX];
  bool subindo;
  bool descendo;
  bool emMovimento;
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
  bool getSubindo();
  bool getDescendo();
  bool getEmMovimento();
  void setSubindo(bool i);
  void setDescendo(bool i);
  void setEmMovimento(bool i);
  Porta getPorta();
  Indicador getIndicador();
  int getBotoesApertados();
  Botao getBotaoAbre();
  Botao getBotaoFecha();
  Botao* getBotaoPainel(int i);
};
#endif
