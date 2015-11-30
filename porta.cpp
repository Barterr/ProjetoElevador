#include "porta.h"

/**
 * Construtor sem parametros
 */
Porta::Porta() {
  aberta = 0;
  sensor = 0;
}

/**
 * Verifica se a porta está aberta
 * @method Porta::estaAberta
 * @return true se está aberta, false se não está
 */
bool Porta::estaAberta() {
  return aberta;
}

/**
 * Verifica o valor do sensor da porta
 * @method Porta::getSensor
 * @return true se o sensor está ativado (algo bloqueando a porta), false se não
 */
bool Porta::getSensor() {
  return sensor;
}

/**
 * Seta valor do sensor
 * @method Porta::setSensor
 * @param  value            valor a ser setado
 */
void Porta::setSensor(bool value) {
  sensor = value;
}

/**
 * Abre a porta
 * @method Porta::abrir
 */
void Porta::abrir() {
  std::this_thread::sleep_for(std::chrono::milliseconds(500));
  aberta = 1;
}

/**
 * Fecha a porta
 * @method Porta::fechar
 */
void Porta::fechar() {
  if (!sensor) {
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    aberta = 0;
  }
}
