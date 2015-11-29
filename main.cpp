#define PISOMAX 5
#define NUMELEVADORES 2
#include <iostream>
#include <chrono>
#include <thread>
#include "botao.cpp"
#include "porta.cpp"
#include "indicador.cpp"
#include "andar.cpp"
#include "elevador.cpp"
using namespace std;

int main (){
  Elevador elevador;
  cout << "Andar: " << elevador.getAndar() << endl;
  cout << "Subindo: " << elevador.getSubindo() << endl;
  cout << "Descendo: " << elevador.getDescendo() << endl;
  cout << "EmMovimento: " << elevador.getEmMovimento() << endl;
  cout << "--------------" << endl;
  elevador.subir();
  elevador.subir();
  elevador.subir();
  cout << "Andar: " << elevador.getAndar() << endl;
  cout << "Subindo: " << elevador.getSubindo() << endl;
  cout << "Descendo: " << elevador.getDescendo() << endl;
  cout << "EmMovimento: " << elevador.getEmMovimento() << endl;
  cout << "--------------" << endl;
  elevador.descer();
  elevador.descer();
  cout << "Andar: " << elevador.getAndar() << endl;
  cout << "Subindo: " << elevador.getSubindo() << endl;
  cout << "Descendo: " << elevador.getDescendo() << endl;
  cout << "EmMovimento: " << elevador.getEmMovimento() << endl;
  cout << "--------------" << endl;
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
