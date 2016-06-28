/* 
 * File:   TroncoDeCono.cpp
 * Author: fabricioandres
 * 
 * Created on June 14, 2016, 9:41 AM
 */
#include "TroncoDeCono.h"
#include <iostream>

using namespace std;

TroncoDeCono::TroncoDeCono(double r1, double r2, double h):Circulo(r1), radio2(r2), altura(h){
}

TroncoDeCono::TroncoDeCono(const TroncoDeCono& orig) {
}

TroncoDeCono::~TroncoDeCono() {
}

void TroncoDeCono::SetAltura(double altura) {
    this->altura = altura;
}

double TroncoDeCono::GetAltura() const {
    return altura;
}

void TroncoDeCono::SetRadio2(double radio2) {
    this->radio2 = radio2;
}

double TroncoDeCono::GetRadio2() const {
    return radio2;
}

double TroncoDeCono::volumen(){
    return(1.0/3)*3.14169 * altura(radio * radio + radio2*radio2 + radio*radio2);
}

void TroncoDeCono::imprimirDatos(){
    cout << "Tronco de cono: "<< radio << " " << " " << radio2 << " " << altura 
            << " " << this->volumen() << endl;
}
