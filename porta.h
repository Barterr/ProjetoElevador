#ifndef PORTA_H
#define PORTA_H

class Porta {
private:
        bool aberta;
        bool sensor;
public:
        Porta();
        bool estaAberta();
        bool getSensor();
        void setSensor(bool a);
        void abrir();
        void fechar();
};
#endif
