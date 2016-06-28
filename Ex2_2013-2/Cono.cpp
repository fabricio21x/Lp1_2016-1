/* 
 * File:   Cono.cpp
 * Author: fabricioandres
 * 
 * Created on June 14, 2016, 9:41 AM
 */
#include "Cono.h"
#include <iostream>

using namespace std;

Cono::Cono(double radio, double altura):Circulo(radio), altura(altura){
}

Cono::Cono(const Cono& orig) {
}

Cono::~Cono() {
}

void Cono::SetAltura(double altura) {
    this->altura = altura;
}

double Cono::GetAltura() const {
    return altura;
}

double Cono::volumen(){
    return(1.0/3)*3.14169 * radio * radio * altura;
}

void Cono::imprimirDatos(){
    cout << "Cono: "<< radio << " " << altura << " " << this->volumen() << endl;
}