#include "controlador.h"
#include <iostream>
using namespace std;

Controlador::Controlador(){
}

void Controlador::threadControlador(){

  atualizaArrays();



}

void Controlador::atualizaArrays(){
  int botoesApertados[NUMELEVADORES];

  for (int i = 0; i < NUMELEVADORES; i++) {
    botoesApertados[i] = elevadores[i].getBotoesApertados();
  }

  for (int i = 0; i < NUMELEVADORES; i++) {
    for (int j = 0; j < PISOMAX; j++) {
      andaresParar[i][j] = botoesApertados[i] & 0x01;
      botoesApertados[i] >>= 1;
    }
  }




}

void Controlador::acionamentos(){
  // int andarDestino;
  // for (int i = 0; i < NUMELEVADORES; i++) {
  //   /* code */
  //
  //   if (elevadores[i].getDescendo()){
  //     for (int k = PISOMAX; k >= 0; k--) {
  //       if (andarandaresParar[k]){
  //         andarDestino = k;
  //       }
  //     }
  //     if (elevadores[i].getSubindo()){
  //       for (int k = 0; k < PISOMAX; k--) {
  //         if (andarandaresParar[k]){
  //           andarDestino = k;
  //         }
  //       }
  //     }
  //   }
  //
  // }

  // if (elevadores[i].getAndar()) {
  //   emMovimento =0;
  //
  // }

}
void Controlador::procedimentosFinais(){

}

Elevador* Controlador::getElevador(int id){
  return &elevadores[id];

}
