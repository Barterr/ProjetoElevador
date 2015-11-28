#ifndef ANDAR_H
#define ANDAR_H

class Andar{
private:
  Porta portas[2];
  Indicador indicadores[2];
  Botao botaoSubir;
  Botao botaoDescer;
public:
  Andar();
  Porta getPorta(int idElevador);
  Indicador getIndicador(int idElevador);
  Botao getBotaoSubir();
  Botao getBotaoDescer();
}
