#define PISOMAX 10
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
using namespace std;

void foo(Elevador* elevador) {
  while(1) {
    elevador->mover();
  }
}

void printelevador0(Elevador* elevador, int i) {
  cout << "Elevador " << i << endl;
  cout << "Andar: " << elevador->getAndar() << endl;
  cout << "Subindo: " << elevador->getDescendo() << endl;
  cout << "Descendo: " << elevador->getSubindo() << endl;
  cout << "Em Movimento: " << elevador->getEmMovimento() << endl;
}

int main() {
  Controlador controlador;
  std::thread first (foo, controlador.getElevador(0));

  printelevador0(controlador.getElevador(0), 0);

  controlador.getElevador(0)->getBotaoPainel(5)->apertar();

  this_thread::sleep_for(chrono::milliseconds(500));
  //usleep(chrono::milliseconds(500));
  printelevador0(controlador.getElevador(0), 0);
  this_thread::sleep_for(chrono::milliseconds(500));
  //usleep(chrono::milliseconds(500));
  printelevador0(controlador.getElevador(0), 0);
  this_thread::sleep_for(chrono::milliseconds(500));
  //usleep(chrono::milliseconds(500));
  printelevador0(controlador.getElevador(0), 0);
  this_thread::sleep_for(chrono::milliseconds(500));
  //usleep(chrono::milliseconds(500));
  printelevador0(controlador.getElevador(0), 0);
  this_thread::sleep_for(chrono::milliseconds(500));
  //usleep(chrono::milliseconds(500));
  printelevador0(controlador.getElevador(0), 0);
  this_thread::sleep_for(chrono::milliseconds(500));
  //usleep(chrono::milliseconds(500));
  printelevador0(controlador.getElevador(0), 0);

  while (1);
  return 0;
}
