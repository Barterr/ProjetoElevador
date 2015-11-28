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
  void subir();
  void descer();
  int getAndar();
  bool getSubindo();
  bool getDescendo();
  bool getEmMovimento();
  Porta getPorta();
  Indicador getIndicador();
  int getBotoesApertados();
};
#endif
