
#include <iostream>
#include <chrono>
#include <thread>
#include "botao.cpp"
#include "porta.cpp"
using namespace std;

int main (){
  Porta porta;
  cout << "Aberta: " << porta.estaAberta() << endl;
  cout << "Sensor: " << porta.getSensor() << endl;
  porta.setSensor(1);
  porta.abrir();
  cout << "Aberta: " << porta.estaAberta() << endl;
  cout << "Sensor: " << porta.getSensor() << endl;
  porta.fechar();
  cout << "Aberta: " << porta.estaAberta() << endl;
  cout << "Sensor: " << porta.getSensor() << endl;
  porta.setSensor(0);
  cout << "Aberta: " << porta.estaAberta() << endl;
  cout << "Sensor: " << porta.getSensor() << endl;
  return 0;
}
