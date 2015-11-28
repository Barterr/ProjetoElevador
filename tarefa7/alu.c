#include <stdint.h>
#include <time.h>
#include <stdlib.h>

//Global structs and variables declaration
struct data {
	uint8_t arg1;
	uint8_t arg2;
	uint8_t ctrl;
};

uint8_t num1[30], num2[30], num3[30], num4[30];
struct data sti;

//Stimuli Generator
struct data stimuli()
{
	struct data gen_stimuli;
	srand(time(NULL));
	uint8_t r1 = rand()%100;
	uint8_t r2 = rand()%100;
	uint8_t r3 = rand()%6;
	gen_stimuli.arg1 = r1;
	gen_stimuli.arg2 = r2;
	gen_stimuli.ctrl = r3;
	return gen_stimuli;
}

uint8_t alu_add(uint8_t ent1, uint8_t ent2){
	return (ent1 + ent2);
}

uint8_t alu_sub(uint8_t ent1, uint8_t ent2){
	return (ent1 - ent2);
}

uint8_t alu_and(uint8_t ent1, uint8_t ent2){
	return (ent1 & ent2);
}

uint8_t alu_or(uint8_t ent1, uint8_t ent2){
	return (ent1 | ent2);
}

uint8_t alu_xor(uint8_t ent1, uint8_t ent2){
	return (ent1 ^ ent2);
}

uint8_t alu_not(uint8_t ent1){
	return (~ent1);
}

uint8_t alu(uint8_t ent1, uint8_t ent2, uint8_t controle){
	uint8_t saida;
	switch (controle){
			case 0:	
				saida = alu_add(ent1,ent2);
				break;
			case 1: 
				saida = alu_sub(ent1,ent2);
				break;
			case 2:	
				saida = alu_and(ent1,ent2);
				break;
			case 3: 
				saida = alu_or(ent1,ent2);
				break;
			case 4:	
				saida = alu_xor(ent1,ent2);
				break;
			case 5: 
				saida = alu_not(ent1);
				break;
		}
	return saida;
}


int main(){
	int i;
	for(i=0; i<30; i++){
		sti=stimuli();

		num1[i] = sti.arg1;
		num2[i] = sti.arg2;
		num3[i] = sti.ctrl;
		num4[i] = alu(sti.arg1, sti.arg2, sti.ctrl);
	}
	return 0;
}