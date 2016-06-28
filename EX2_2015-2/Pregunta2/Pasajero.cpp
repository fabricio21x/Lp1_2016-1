/* 
 * File:   Pasajero.cpp
 * Author: fabricioandres
 * 
 * Created on June 21, 2016, 8:23 AM
 */

#include "Pasajero.h"
#include <iostream>

using namespace std;

Pasajero::Pasajero(int dni, char* nombre, char* destino) {
    this->dni = dni;
    
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre,nombre);
    
    this->destino = new char[strlen(destino) + 1];
    strcpy(this->destino,destino);
}

Pasajero::Pasajero(const Pasajero& orig) {
    inicializarPasajero();
    this->SetCadena(this->destino,orig.GetDestino());
    this->SetCadena(this->nombre,orig.GetNombre());
    this->dni = orig.GetDni();
}

Pasajero::~Pasajero() {
    delete[] this->destino;
    delete[] this->nombre;
}

void Pasajero::inicializarPasajero(){
    this->destino = NULL;
    this->nombre = NULL;
}

char* Pasajero::GetDestino() const {
    return this->CopiarCadena(this->destino);
}

char* Pasajero::GetNombre() const {
    return this->CopiarCadena(this->nombre);
}

int Pasajero::GetDni() const {
    return dni;
}

void Pasajero::SetDestino(char* destino) {
    this->destino = new char[strlen(destino) + 1];
    strcpy(this->destino,destino);
}

void Pasajero::SetNombre(char* nombre) {
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre,nombre);
}

void Pasajero::SetDni(int dni) {
    this->dni = dni;
}

char* Pasajero::CopiarCadena(char *miCadena) const {
    char *copiaCadena = new char[strlen(miCadena) + 1];
    strcpy(copiaCadena, miCadena);
    return copiaCadena;
}

void Pasajero::SetCadena(char *&miCadena, char *nuevaCadena){
    if (miCadena != NULL)
        delete[] miCadena;
    miCadena = new char[strlen(nuevaCadena) + 1];
    strcpy(miCadena, nuevaCadena);
}

Pasajero& Pasajero::operator=(const Pasajero &pas){
    inicializarPasajero();
    this->SetCadena(this->destino,pas.GetDestino());
    this->SetCadena(this->nombre,pas.GetNombre());
    this->dni = pas.GetDni();
    
    return *this;
}

bool operator<(const Pasajero &p1, const Pasajero &p2){
    return p1.dni < p2.dni;
}