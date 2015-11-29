#ifndef ELEVADOR_H
#define ELEVADOR_H

class Elevador {
private:
  Botao botoes [PISOMAX];
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
  void setSubindo(int i);
  void setDescendo(int i);
  void setEmMovimento(int i);
  Porta getPorta();
  Indicador getIndicador();
  int getBotoesApertados();
  Botao getBotaoAbre();
  Botao getBotaoFecha();
};
#endif
