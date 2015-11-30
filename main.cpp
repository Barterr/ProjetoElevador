#define PISOMAX 12
#define NUMELEVADORES 3
#include <iostream>
#include <chrono>
#include <thread>
#include <bitset>
#include <cmath>
#include "botao.cpp"
#include "porta.cpp"
#include "indicador.cpp"
#include "andar.cpp"
#include "elevador.cpp"
#include "controlador.cpp"
#include "headimprime.cpp"
using namespace std;

void printelevador0(Controlador *controlador) {
  #ifdef linux
  system("clear");
  #endif
  #ifdef _WIN32
  system("cls");
  #endif
  int chamadasSubir = 0;
  int chamadasDescer = 0;
  int andaresParar[NUMELEVADORES];
  for (int i = PISOMAX - 1; i >= 0; i--) {
    chamadasSubir <<= 1;
    chamadasSubir  += controlador->chamadasSubir[i];
    chamadasDescer <<= 1;
    chamadasDescer  += controlador->chamadasDescer[i];
    for (int j = NUMELEVADORES; j >= 0; j--) {
      andaresParar[j] <<= 1;
      andaresParar[j] += controlador->andaresParar[j][i];
    }
  }
  imprime(""); imprime("Elevador 0"); imprime("Elevador 1"); cout << endl;
  imprime("------------"); imprime("------------"); imprime("------------"); cout << endl;
  imprime("Proximo Destino"); imprime(controlador->getProximoDestino(0)); imprime(controlador->getProximoDestino(1)); cout << endl;
  imprime("Tem Pendencias"); imprime((controlador->temPendencias(0))?"Sim":"Nao"); imprime((controlador->temPendencias(1))?"Sim":"Nao"); cout << endl;
  imprime("Porta Aberta"); imprime((controlador->getElevador(0)->getPorta()->estaAberta())?"Aberta":"Fechada"); imprime((controlador->getElevador(1)->getPorta()->estaAberta())?"Aberta":"Fechada"); cout << endl;
  imprime("Andares Parar"); imprime(bitset<PISOMAX>(andaresParar[0])); imprime(bitset<PISOMAX>(andaresParar[1])); cout << endl;
  imprime("Andar"); imprime(controlador->getElevador(0)->getAndar()); imprime(controlador->getElevador(1)->getAndar()); cout << endl;
  imprime("Subindo     /\\"); imprime(controlador->getElevador(0)->getSubindo()); imprime(controlador->getElevador(1)->getSubindo()); cout << endl;
  imprime("Descendo    \\/"); imprime(controlador->getElevador(0)->getDescendo()); imprime(controlador->getElevador(1)->getDescendo()); cout << endl;
  imprime("Em Movimento"); imprime(controlador->getElevador(0)->getEmMovimento()); imprime(controlador->getElevador(1)->getEmMovimento()); cout << endl;
  imprime("Flag Parar"); imprime(controlador->getElevador(0)->getFlagParar()); imprime(controlador->getElevador(1)->getFlagParar()); cout << endl;
  imprime("------------"); imprime("------------"); imprime("------------"); cout << endl;
  imprime("Chamadas Subir"); imprime(bitset<PISOMAX>(chamadasSubir)); cout << endl;
  imprime("Chamadas Descer"); imprime(bitset<PISOMAX>(chamadasDescer)); cout << endl;
}

int main() {
  Controlador control;

  thread first(control.getElevador(0)->mover, control.getElevador(0));
  thread second(control.getElevador(1)->mover, control.getElevador(1));
  thread contThread(control.threadControlador, &control);

  control.getElevador(0)->andar = 6;
  control.getElevador(0)->getBotaoPainel(9)->apertar();
  control.getElevador(0)->getBotaoPainel(1)->apertar();

  printelevador0(&control);
  // this_thread::sleep_for(chrono::milliseconds(1000));
  // control.andares[5].getBotaoDescer()->apertar();
  // control.getElevador(1)->setEmMovimento(1);
  // control.getElevador(1)->setDescendo(1);
  // control.getElevador(0)->setEmMovimento(1);
  // control.getElevador(0)->setSubindo(1);

  // usleep(chrono::milliseconds(500));
  while (1) {
    printelevador0(&control);

    this_thread::sleep_for(chrono::milliseconds(100));

  }
  return 0;
}
