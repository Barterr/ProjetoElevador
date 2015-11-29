#define PISOMAX 12
#define NUMELEVADORES 2
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

void foo(Elevador *elevador) {
  while (1) {
    elevador->mover();
  }
}

void bar(Controlador *controlador) {
  while (1) {
    controlador->threadControlador();
  }
}

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
  imprime("Tem Pendencias"); imprime(controlador->pendencias[0]); imprime(controlador->pendencias[1]); cout << endl;
  imprime("Tem Pendencias2"); imprime(controlador->temPendencias(0)); imprime(controlador->temPendencias(1)); cout << endl;
  imprime("Porta"); imprime(controlador->getElevador(0)->getPorta()->estaAberta()); imprime(controlador->getElevador(1)->getPorta()->estaAberta()); cout << endl;
  imprime("Andares Parar"); imprime(bitset<PISOMAX>(andaresParar[0])); imprime(bitset<PISOMAX>(andaresParar[1])); cout << endl;
  imprime("Andar"); imprime(controlador->getElevador(0)->getAndar()); imprime(controlador->getElevador(1)->getAndar()); cout << endl;
  imprime("Descendo"); imprime(controlador->getElevador(0)->getDescendo()); imprime(controlador->getElevador(1)->getDescendo()); cout << endl;
  imprime("Subindo"); imprime(controlador->getElevador(0)->getSubindo()); imprime(controlador->getElevador(1)->getSubindo()); cout << endl;

  imprime("Em Movimento"); imprime(controlador->getElevador(0)->getEmMovimento()); imprime(controlador->getElevador(1)->getEmMovimento()); cout << endl;
  imprime("------------"); imprime("------------"); imprime("------------"); cout << endl;
  imprime("Chamadas Subir"); imprime(bitset<PISOMAX>(chamadasSubir)); cout << endl;
  imprime("Chamadas Descer"); imprime(bitset<PISOMAX>(chamadasDescer)); cout << endl;
}

int main() {
  Controlador controlador;

  thread first(foo, controlador.getElevador(0));
  thread second(foo, controlador.getElevador(1));
  thread contthread(bar, &controlador);

  printelevador0(&controlador);
  // controlador.getElevador(0)->getBotaoPainel(5)->apertar();
  this_thread::sleep_for(chrono::milliseconds(2000));
  controlador.getElevador(1)->getBotaoPainel(7)->apertar();
  // controlador.andares[1].getBotaoDescer()->apertar();
  //
  // controlador.getElevador(0)->setEmMovimento(1);
  controlador.getElevador(1)->andar = 5;
  controlador.getElevador(1)->setEmMovimento(1);
  controlador.getElevador(1)->setSubindo(1);

  // usleep(chrono::milliseconds(500));
  while (1) {
    printelevador0(&controlador);

    this_thread::sleep_for(chrono::milliseconds(100));
  }

  while (1);
  return 0;
}
