#define PISOMAX 10
#define NUMELEVADORES 2
#include <iostream>
#include <chrono>
#include <thread>
#include <bitset>
#include "botao.cpp"
#include "porta.cpp"
#include "indicador.cpp"
#include "andar.cpp"
#include "elevador.cpp"
using namespace std;

int main (){
  Elevador elevador;
  Botao botao;
  cout << "Botao apertado: " << botao.estaPressionado() << endl;
  botao.apertar();
  cout << "Botao apertado: " << botao.estaPressionado() << endl;
  cout << "Andar: " << elevador.getAndar() << endl;
  cout << "Subindo: " << elevador.getSubindo() << endl;
  cout << "Descendo: " << elevador.getDescendo() << endl;
  cout << "EmMovimento: " << elevador.getEmMovimento() << endl;
  cout << "--------------" << endl;
  // elevador.botoesPainel[1]->apertar();
  // elevador.botoesPainel[3]->apertar();
  // Botao asdqwe = elevador.getBotaoPainel(0);
  // elevador.getBotaoPainel(0).apertar();
  // asdqwe.apertar();
  elevador.getBotaoPainel(0)->apertar();
  elevador.getBotaoPainel(1)->apertar();
  elevador.getBotaoPainel(2)->desapertar();
  elevador.getBotaoPainel(3)->apertar();
  elevador.getBotaoPainel(4)->apertar();
  elevador.getBotaoPainel(9)->apertar();
  cout << "botoes apertados: " << bitset<10>(elevador.getBotoesApertados()) << endl;

  // cout << "botoes apertados: " << out << endl;
  cout << elevador.getBotaoPainel(0)->estaPressionado() << endl;
  cout << elevador.getBotaoPainel(1)->estaPressionado() << endl;
  cout << elevador.getBotaoPainel(2)->estaPressionado() << endl;
  cout << elevador.getBotaoPainel(3)->estaPressionado() << endl;
  cout << elevador.getBotaoPainel(4)->estaPressionado() << endl;
  // cout << "Indicador 1 ID: " << andar.getIndicador(1)->elevador << endl;
  // cout << "Porta 0 aberta?: " << andar.getPorta(0)->estaAberta() << endl;
  // cout << "Porta 1 aberta?: " << andar.getPorta(1)->estaAberta() << endl;
  // andar.getPorta(1)->abrir();
  // cout << "Porta 0 aberta?: " << andar.getPorta(0)->estaAberta() << endl;
  // cout << "Porta 1 aberta?: " << andar.getPorta(1)->estaAberta() << endl;
  // andar.getPorta(0)->abrir();
  // cout << "Porta 0 aberta?: " << andar.getPorta(0)->estaAberta() << endl;
  // cout << "Porta 1 aberta?: " << andar.getPorta(1)->estaAberta() << endl;
  // // cout << "Descendo: " << indicador.descendo << endl;
  // // cout << "Andar: " << indicador.andarElevador << endl;
  string asd;
  cin >> asd;

  return 0;
}
