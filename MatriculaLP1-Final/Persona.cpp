/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Persona.cpp
 * Author: fernandoalva
 * 
 * Created on June 8, 2016, 9:09 AM
 */

#include "Persona.h"
#include <iostream>
using namespace std;

Persona::Persona() {
    //cout << "Constructor Persona..." << endl;
    inicializarPersona();
}

Persona::Persona(int codigo, char *nombre, char *apellido, char *especialidad){
    inicializarPersona();
    this->SetCodigo(codigo);
    this->SetNombre(nombre);
    this->SetApellido(apellido);
    this->SetEspecialidad(especialidad);
}

Persona::Persona(const Persona& orig) {
    inicializarPersona();
    this->SetCodigo(orig.codigo);
    this->SetNombre(orig.nombre);
    this->SetApellido(orig.apellido);
    this->SetEspecialidad(orig.especialidad);
}

Persona::~Persona() {
    //cout << "Destructor Persona..." << endl;
    delete[] this->nombre;
    delete[] this->apellido;
    delete[] this->especialidad;
}

void Persona::inicializarPersona(){
    this->nombre = NULL;
    this->apellido = NULL;
    this->especialidad = NULL;
}

void Persona::SetEspecialidad(char* especialidad) {
    this->SetCadena(this->especialidad, especialidad);
}

char* Persona::GetEspecialidad() const{
    return this->CopiarCadena(this->especialidad);
}

void Persona::SetApellido(char* apellido) {
    this->SetCadena(this->apellido, apellido);
}

char* Persona::GetApellido() const{
    return this->CopiarCadena(this->apellido);
}

void Persona::SetNombre(char* nombre) {
    this->SetCadena(this->nombre, nombre);
}

char* Persona::GetNombre() const {
    return this->CopiarCadena(this->nombre);
}

void Persona::SetCodigo(int codigo) {
    if (codigo > 9999999 && codigo < 100000000)
        this->codigo = codigo;
}

int Persona::GetCodigo() const{
    return this->codigo;
}

void Persona::SetCadena(char *&miCadena, char *nuevaCadena){
    if (miCadena != NULL)
        delete[] miCadena;
    miCadena = new char[strlen(nuevaCadena) + 1];
    strcpy(miCadena, nuevaCadena);
}

char *Persona::CopiarCadena(char *miCadena) const {
    char *copiaCadena = new char[strlen(miCadena) + 1];
    strcpy(copiaCadena, miCadena);
    return copiaCadena;
}

//void Persona::imprimirIdentidad(){
//    cout << "????" << endl;
//}
