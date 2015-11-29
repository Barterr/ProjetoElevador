#ifndef BOTAO_H
#define BOTAO_H

class Botao {
private:
        bool pressionado;
public:
        Botao();
        bool estaPressionado();
        void apertar();
        void desapertar();
};
#endif
