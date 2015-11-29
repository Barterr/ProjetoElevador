#include "botao.h"

/**
 * Construtor da classe Botao
 */
Botao::Botao (){
  pressionado = 0;
}

/**
 * Verifica se o botão está pressionado
 * @method Botao::estaPressionado
 * @return true se pressionado, false se não
 */
bool Botao::estaPressionado(){
 return pressionado;
}

/**
 * Aperta o botão
 * @method Botao::apertar
 */
void Botao::apertar(){
 pressionado = 1;
}

/**
 * Desaperta o botão
 * @method Botao::desapertar
 */
void Botao::desapertar(){
  pressionado = 0;
}
