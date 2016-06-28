/* 
 * File:   Omnibus.cpp
 * Author: fabricioandres
 * 
 * Created on June 21, 2016, 8:23 AM
 */

#include "Omnibus.h"
#include <algorithm>
#include <iostream>

using namespace std;

Omnibus::Omnibus() {
    this->numAsientos = 0;  
    inicializaBus();
}

Omnibus::Omnibus(const Omnibus& orig) {
    inicializaBus();
    this->SetChofer(orig.chofer);
    this->SetPlaca(orig.placa);
    this->numAsientos = orig.numAsientos;
    this->ruta = orig.ruta;
    this->pasajeros = orig.pasajeros;
}

Omnibus::~Omnibus() {
//    delete[] this->placa;
//    delete[] this->chofer;
}

void Omnibus::inicializaBus(){
    this->chofer = NULL;
    this->placa = NULL;
}

int Omnibus::GetNumAsientos() const {
    return numAsientos;
}

char* Omnibus::GetChofer() const {
    return this->CopiarCadena(this->chofer);
}

char* Omnibus::GetPlaca() const {
    return this->CopiarCadena(this->placa);
}

void Omnibus::SetNumAsientos(int numAsientos) {
    this->numAsientos = numAsientos;
}

void Omnibus::SetChofer(char* chofer) {
    this->SetCadena(this->chofer,chofer);
}

void Omnibus::SetPlaca(char* placa) {
    this->SetCadena(this->placa,placa);
}

void Omnibus::AgregarRuta(char* ruta){
    this->ruta.push_back(ruta);
}

bool Omnibus::BuscarRuta(char *destino){
    for (auto elem : ruta) {
        if (strcmp(destino, elem) == 0)
            return true;
    }
    return false;
}
int Omnibus::AsientosOcupados(){
    return this->pasajeros.size();
}

void Omnibus::AgregarPasajero(int dni, char* nombre, char* destino){
    Pasajero pasajero(dni, nombre, destino);

    this->pasajeros.push_back(pasajero);
}

void Omnibus::ImprimirRutas(){
    for (auto elem : ruta) {
        cout << elem << ' ';
    }

}

void Omnibus::ImprimirPasajerosXRuta(){
    int i;
    for (auto elem : ruta) {
        i=1;
        cout << elem << ':' << endl;
        cout << "No\tDNI\t\t\tNOMBRE"<< endl;
        for (auto pas : pasajeros) {
            if (strcmp(elem,pas.GetDestino()) == 0){
                cout << i << '\t'<< pas.GetDni() << "\t\t" << pas.GetNombre() << endl;
                i++;
            }
        }        
        cout << endl;
    }

}

Omnibus& Omnibus::operator=(const Omnibus &omn){
    inicializaBus();
    this->SetChofer(omn.chofer);
    this->SetPlaca(omn.placa);
    this->numAsientos = omn.numAsientos;
    this->ruta = omn.ruta;
    this->pasajeros = omn.pasajeros;
    return *this;
}

void Omnibus::ordenarPasajeros(){
    sort(this->pasajeros.begin(),this->pasajeros.end());
}

void Omnibus::SetCadena(char *&miCadena, char *nuevaCadena){
    if (miCadena != NULL)
        delete[] miCadena;   
    miCadena = new char[strlen(nuevaCadena) + 1];
    strcpy(miCadena, nuevaCadena);
}

char* Omnibus::CopiarCadena(char *miCadena) const {
    char *copiaCadena = new char[strlen(miCadena) + 1];
    strcpy(copiaCadena, miCadena);
    return copiaCadena;
}

bool operator<(const Omnibus &omn1, const Omnibus &omn2){
    if (strcmp(omn1.placa,omn2.placa) < 0){
        return true;
    }else return false;      
}