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
  cout << "-----------------" << endl;
}

int main() {
  Controlador controlador;

  thread first (foo, controlador.getElevador(0));
  thread contthread (&Controlador::threadControlador,controlador);

  printelevador0(controlador.getElevador(0), 0);

  controlador.getElevador(0)->getBotaoPainel(5)->apertar();

  this_thread::sleep_for(chrono::milliseconds(1000));
  controlador.getElevador(0)->setEmMovimento(1);
  controlador.getElevador(0)->setSubindo(1);
  //usleep(chrono::milliseconds(500));
  while(1) {
    cout << "Proximo Destino: " << controlador.getProximoDestino(0) << endl;
    printelevador0(controlador.getElevador(0), 0);

    this_thread::sleep_for(chrono::milliseconds(200));
}

  while (1);
  return 0;
}
