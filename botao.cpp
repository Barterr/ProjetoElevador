#include "botao.h"

Botao::Botao (){
  pressionado = 0;
}

bool Botao::estaPressionado(){
 return pressionado;
}

void Botao::apertar(){
 pressionado = 1;
}

void Botao::desapertar(){
  pressionado = 0;
}
