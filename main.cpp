
#ifdef WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // win32

#include <iostream>
#include <unistd.h>
#include "botao.cpp"
#include "porta.cpp"

using namespace std;

void sleepcp(int milliseconds){
    #ifdef WIN32
    Sleep(milliseconds);
    #else
    usleep(milliseconds * 1000);
    #endif // win32
}

int main (){
  Porta porta;
  cout << "Aberta: " << porta.estaAberta() << endl;
  cout << "Sensor: " << porta.getSensor() << endl;
  sleepcp(3*1000);
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
