#ifndef ANDAR_H
#define ANDAR_H

class Andar {
public:
        Porta portas[NUMELEVADORES];
        Indicador indicadores[NUMELEVADORES];
        Botao botaoSubir;
        Botao botaoDescer;
        bool flagsFecharPorta[NUMELEVADORES];
        bool flagsAbrirPorta[NUMELEVADORES];
public:
        Andar();
        void threadPortas();
        Porta* getPorta(int idElevador);
        Indicador* getIndicador(int idElevador);
        Botao* getBotaoSubir();
        Botao* getBotaoDescer();
};
#endif
