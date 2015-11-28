#include "botao.h"

void Botao::Botao (){
  pressionado = 0;
}

bool Botao::estaPressionado(){
 return pressionado;
}

void Botao::apertar(){
 pressionado = TRUE;
}

void Botao::desapertar(){
  pressionado = FALSE;
}
