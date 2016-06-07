#include "Alumno.h"
#include <cstring>
#include <iostream>

using namespace std;

Alumno::Alumno(){
    this->nombre = NULL;
    this->apellido = NULL;
    this->especialidad = NULL;
}

Alumno::Alumno(char *linea){
    int codigo;
    char *nombre, *apellido, *especialidad;
    double craest;
    
    SeparaDatos(linea, codigo, nombre, apellido, especialidad, craest);
    
    SetCodigo(codigo);
    SetNombre(nombre);
    SetApellido(apellido);
    SetEspecialidad(especialidad);
    SetCraest(craest);
    
    delete[] nombre;
    delete[] apellido;
    delete[] especialidad;
}


Alumno::Alumno(int codigo, char* nombre, char* apellido){
    this->SetCodigo(codigo);
    this->SetNombre(nombre);
    this->SetApellido(apellido);
}

Alumno::~Alumno() {
    delete[] this->nombre;
    delete[] this->apellido;
    delete[] this->especialidad;
}

void Alumno::SetCraest(double craest) {
    if (craest > 0.0)
        this->craest = craest;
}

double Alumno::GetCraest(){
    return craest;
}

void Alumno::SetEspecialidad(char* especialidad) {
    this->SetCadena(this->especialidad, especialidad);
}

char* Alumno::GetEspecialidad(){
    return this->CopiarCadena(this->especialidad);
}

void Alumno::SetApellido(char* apellido) {
    this->SetCadena(this->apellido, apellido);
}

char* Alumno::GetApellido(){
    return this->CopiarCadena(this->apellido);
}

void Alumno::SetNombre(char* nombre) {
    this->SetCadena(this->nombre, nombre);
}

char* Alumno::GetNombre() {
    return this->CopiarCadena(this->nombre);
}

void Alumno::SetCodigo(int codigo) {
    if (codigo > 9999999 && codigo < 100000000)
        this->codigo = codigo;
}

int Alumno::GetCodigo(){
    return this->codigo;
}

void Alumno::SetCadena(char *&miCadena, char *nuevaCadena){
    if (miCadena != NULL)
        delete[] miCadena;
    miCadena = new char[strlen(nuevaCadena) + 1];
    strcpy(miCadena, nuevaCadena);
}

char *Alumno::CopiarCadena(char *miCadena){
    char *copiaCadena = new char[strlen(miCadena) + 1];
    strcpy(copiaCadena, miCadena);
    return copiaCadena;
}

void Alumno::SeparaDatos(char *linea, int &codigo, char *&nombre, char *&apellido, char *&especialidad, double &craest){
    char *pal = strtok(linea, ",");
    codigo = atoi(pal);
    
    pal = strtok(NULL, ",");
    nombre = new char[strlen(pal) + 1];
    strcpy(nombre, pal);
    
    pal = strtok(NULL, ",");
    apellido = new char[strlen(pal) + 1];
    strcpy(apellido, pal);
    
    pal = strtok(NULL, ",");
    especialidad = new char[strlen(pal) + 1];
    strcpy(especialidad, pal);
    
    pal = strtok(NULL, ",");
    craest = atof(pal);    
}

istream& operator>>(istream &in, Alumno &alum){
    int codigo;
    char nombre[30], apellido[30], especialidad[30];
    double craest;
    
    in >> codigo >> nombre >> apellido >> especialidad >> craest;
    alum.codigo = codigo;
    alum.nombre = nombre;
    alum.apellido = apellido;
    alum.especialidad = especialidad;
    alum.craest = craest;
    
    return in;
}

ostream& operator<<(ostream &out,const Alumno &alum){
    out << alum.codigo << endl;
    out << alum.nombre << '\t' << alum.apellido << '\t' 
            << alum.especialidad << '\t' << alum.craest << endl;
    
    return out;
}
