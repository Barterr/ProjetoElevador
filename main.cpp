#define PISOMAX 10
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

void printInfo(Controlador *controlador) {
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
  imprime("Ultimo Destino"); imprime(controlador->getUltimoDestino(0)); imprime(controlador->getUltimoDestino(1)); cout << endl;
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
  this_thread::sleep_for(chrono::milliseconds(100));
}

int main() {
  Controlador control;

  thread elev0(control.getElevador(0)->mover, control.getElevador(0));
  thread elev1(control.getElevador(1)->mover, control.getElevador(1));
  thread portasElev0(control.getElevador(0)->threadPortas, control.getElevador(0));
  thread portasElev1(control.getElevador(1)->threadPortas, control.getElevador(1));
  // thread portasAndar0(control.andares[0].threadPortas, &control.andares[0]);
  // thread portasAndar1(control.andares[1].threadPortas, &control.andares[1]);
  // thread portasAndar2(control.andares[2].threadPortas, &control.andares[2]);
  // thread portasAndar3(control.andares[3].threadPortas, &control.andares[3]);
  // thread portasAndar4(control.andares[4].threadPortas, &control.andares[4]);
  // thread portasAndar5(control.andares[5].threadPortas, &control.andares[5]);
  // thread portasAndar6(control.andares[6].threadPortas, &control.andares[6]);
  // thread portasAndar7(control.andares[7].threadPortas, &control.andares[7]);
  // thread portasAndar8(control.andares[8].threadPortas, &control.andares[8]);
  // thread portasAndar9(control.andares[9].threadPortas, &control.andares[9]);
  // thread portasAndar10(control.andares[10].threadPortas, &control.andares[10]);
  thread contThread(control.threadControlador, &control);

  // thread printThread(printInfo, &control);

  control.getElevador(0)->andar = 4;
  control.getElevador(1)->andar = 5;
  control.getElevador(1)->getBotaoPainel(1)->apertar();
  control.getElevador(1)->getBotaoPainel(9)->apertar();
  control.andares[9].getBotaoDescer()->apertar();
  control.andares[1].getBotaoSubir()->apertar();
  // control.getElevador(0)->getBotaoPainel(6)->apertar();
  // control.getElevador(0)->getBotaoPainel(2)->apertar();
  // control.getElevador(0)->getBotaoPainel(0)->apertar();
  // control.getElevador(1)->getBotaoPainel(7)->apertar();
  // control.getElevador(1)->getBotaoPainel(2)->apertar();
  // control.getElevador(1)->getBotaoPainel(3)->apertar();

  while (1) {printInfo(&control);}
  return 0;
}
