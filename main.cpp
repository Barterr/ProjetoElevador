
#include <iostream>
#include <chrono>
#include <thread>
#include "botao.cpp"
#include "porta.cpp"
using namespace std;

int main (){
  thread test (test);
  return 0;
}

void test(){
  Porta porta;
  cout << "Aberta: " << porta.estaAberta() << endl;
  cout << "Sensor: " << porta.getSensor() << endl;
  this_thread::sleep_for(chrono::milliseconds(3*1000));
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
