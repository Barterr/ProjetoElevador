#include "andar.h"

/**
 * Construtor da classe Andar, cria indicadores para cada elevador
 */
Andar::Andar(){
  for (int i = 0; i < NUMELEVADORES; i++) {
    indicadores[i] = Indicador(i);
  }
}

/**
 * Retorna a porta do poço de certo elevador, há n portas num andar de n elevadores
 * @method Andar::getPorta
 * @param  idElevador      id do elevador
 * @return                 ponteiro da porta
 */
Porta* Andar::getPorta(int idElevador){
  if (idElevador < NUMELEVADORES)
    return &portas[idElevador];
  else
    return NULL;
}

/**
 * Retorna o indicador do andar de certo elevador, há n indicadores num andar de n elevadores
 * @method Andar::getIndicador
 * @param  idElevador          id do elevador
 * @return                     ponteiro do indicador
 */
Indicador* Andar::getIndicador(int idElevador){
  if (idElevador < NUMELEVADORES)
    return &indicadores[idElevador];
  else
    return NULL;
}

/**
 * Retorna o botão que pede um elevador que esteja subindo
 * @method Andar::getBotaoSubir
 * @return ponteiro do botão
 */
Botao* Andar::getBotaoSubir(){
  return &botaoSubir;
}

/**
 * Retorna o botão que pede um elevador que esteja descendo
 * @method Andar::getBotaoDescer
 * @return [description]
 */
Botao* Andar::getBotaoDescer(){
  return &botaoDescer;
}
