#ifndef ANDAR_H
#define ANDAR_H

class Andar {
public:
        Porta portas[NUMELEVADORES];
        Indicador indicadores[NUMELEVADORES];
        Botao botaoSubir;
        Botao botaoDescer;
public:
        Andar();
        Porta* getPorta(int idElevador);
        Indicador* getIndicador(int idElevador);
        Botao* getBotaoSubir();
        Botao* getBotaoDescer();
};
#endif
