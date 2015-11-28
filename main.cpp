
#include <iostream>
#include "botao.cpp"

using namespace std;

int main (){
  Botao botao;
  cout << botao.estaPressionado() << endl;
  botao.apertar();
  cout << botao.estaPressionado() << endl;
  botao.desapertar();
  cout << botao.estaPressionado() << endl;
  return 0;
}
