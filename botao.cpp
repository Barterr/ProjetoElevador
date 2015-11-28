#include "botao.h"

void Botao::Botao (){
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
