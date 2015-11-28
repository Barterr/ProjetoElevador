#ifndef ELEVADOR_H
#define ELEVADOR_H
#include <iostream>
using namespace std;

class Elevador {
	int andarAtual, totalAndares, capacidade, presentes;
public:
	void inicializa (int,int);
	bool entra ();
	bool sai ();
	bool sobe ();
	bool desce ();
	int getAndarAtual ();
	int getTotalAndares ();
	int getCapacidade ();
	int getPresentes ();
};
#endif
