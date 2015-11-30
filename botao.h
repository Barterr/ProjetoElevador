#ifndef BOTAO_H
#define BOTAO_H

class Botao {
private:
        bool pressionado;
        bool atendido;
public:
        Botao();
        bool estaPressionado();
        bool getAtendido();
        void setAtendido(bool);
        void apertar();
        void desapertar();
};
#endif
