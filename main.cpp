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

void printelevador0() {
  cout << "Elevador 0" << endl;
  cout << "Andar: " << controlador.getElevador(0)->getAndar() << endl;
  cout << "Subindo: " << controlador.getElevador(0)->getDescendo() << endl;
  cout << "Descendo: " << controlador.getElevador(0)->getSubindo() << endl;
  cout << "Em Movimento: " << controlador.getElevador(0)->getEmMovimento() << endl;
}

int main() {
  Controlador controlador;

  printelevador0();

  controlador.getElevador(0)->getBotaoPainel(5)->apertar();

  this_thread::sleep_for(chrono::milliseconds(500));
  //usleep(chrono::milliseconds(500));
  printelevador0();
  this_thread::sleep_for(chrono::milliseconds(500));
  //usleep(chrono::milliseconds(500));
  printelevador0();
  this_thread::sleep_for(chrono::milliseconds(500));
  //usleep(chrono::milliseconds(500));
  printelevador0();
  this_thread::sleep_for(chrono::milliseconds(500));
  //usleep(chrono::milliseconds(500));
  printelevador0();
  this_thread::sleep_for(chrono::milliseconds(500));
  //usleep(chrono::milliseconds(500));
  printelevador0();
  this_thread::sleep_for(chrono::milliseconds(500));
  //usleep(chrono::milliseconds(500));
  printelevador0();

  while (1);
  return 0;
}
