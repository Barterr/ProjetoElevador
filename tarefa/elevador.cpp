
#include "elevador.h"

void Elevador::inicializa(int totalAndares, int capacidade){
	Elevador::totalAndares = totalAndares;
	Elevador::capacidade = capacidade;
	presentes = 0;
	andarAtual = 0;
}

bool Elevador::entra(){
	bool erro = false;
	if (presentes < capacidade){
		presentes++;
		erro = true;
		}
	return erro;
}

bool Elevador::sai(){
	bool erro = false;
	if (presentes > 0){
		 presentes--;
		 erro = true;
	}
	return erro;
}

bool Elevador::sobe(){
	bool erro = false;
	if (andarAtual<totalAndares){
		andarAtual++;
		erro = true;
	}
	return erro;
}

bool Elevador::desce(){
	bool erro = false;
	if (andarAtual>0){
		andarAtual--;
		erro = true;
	}
	return erro;
}

int Elevador::getAndarAtual(){
	return andarAtual;
}

int Elevador::getTotalAndares(){
	return totalAndares;
}

int Elevador::getCapacidade(){
	return capacidade;
}

int Elevador::getPresentes(){
	return presentes;
}
