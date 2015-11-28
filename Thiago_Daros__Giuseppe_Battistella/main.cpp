#include "elevador.h"

int main (){

	int andares;
	int capacidade;

	bool on = true;
	int option;

	Elevador elev;

	cout << "Entre com o total de andares:" << endl;
	cin >> andares;
	cout << "Entre com a capacidade do elevador:" << endl;
	cin >> capacidade;

	elev.inicializa(andares,capacidade);

	cout << "1:sobe\n 2:desce\n 3:entra\n 4:sai\n 5:capacidade total\n 6:presentes\n 7:andar atual\n 8:total andares\n 9:sair" << endl;

 	while(on) {
 		cin >> option;
 		switch (option){
 			case 1:
 			if (elev.sobe()) {
 				cout << "Andar atual: " << elev.getAndarAtual()<<endl;
 			}
 			else {
 				cout << "O elevador se encontra no topo, andar: " << elev.getAndarAtual()<<endl;
 			}
 			break;

 			case 2:
 			if (elev.desce()) {
 				cout << "Andar atual: " << elev.getAndarAtual()<<endl;
 			}
 			else {
 				cout << "O elevador se encontra no terreo, andar: " << elev.getAndarAtual()<<endl;
 			}
 			break;

 			case 3:
 			if (elev.entra()) {
 				cout << "Presentes: " << elev.getPresentes()<<endl;
 			}
 			else {
 				cout << "O elevador se encontra cheio, presentes: " << elev.getPresentes()<<endl;
 			}
 			break;

 			case 4:
 			if (elev.sai()) {
 				cout << "Presentes: " << elev.getPresentes()<<endl;
 			}
 			else {
 				cout << "O elevador se encontra vazio, presentes: " << elev.getPresentes()<<endl;
 			}
 			break;

 			case 5:
 			cout << "Capacidade Total: " << elev.getCapacidade()<<endl;
 			break;

 			case 6:
 			cout << "Presentes: " << elev.getPresentes()<<endl;
 			break;

 			case 7:
 			cout << "Andar Atual: " << elev.getAndarAtual()<<endl;
 			break;

 			case 8:
 			cout << "Total de Andares: " << elev.getTotalAndares()<<endl;
 			break;

 			on = false;
 			case 9:
 			break;
 			}
 		}
 	}
