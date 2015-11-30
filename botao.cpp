#include "botao.h"

/**
 * Construtor da classe Botao
 */
Botao::Botao() {
  pressionado = 0;
  atendido = 1;
}

/**
 * Verifica se o botão está pressionado
 * @method Botao::estaPressionado
 * @return true se pressionado, false se não
 */
bool Botao::estaPressionado() {
  return pressionado;
}

bool Botao::getAtendido() {
  return atendido;
}

void Botao::setAtendido(bool valor) {
  atendido = valor;
}

/**
 * Aperta o botão
 * @method Botao::apertar
 */
void Botao::apertar() {
  pressionado = 1;
  atendido = 0;
}

/**
 * Desaperta o botão
 * @method Botao::desapertar
 */
void Botao::desapertar() {
  pressionado = 0;
  atendido = 1;
}
