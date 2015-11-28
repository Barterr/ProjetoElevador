
#include <iostream>
#include <chrono>
#include <thread>
#include "botao.cpp"
#include "porta.cpp"
#include "indicador.cpp"
using namespace std;

int main (){
  Indicador indicador(1);
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
}
