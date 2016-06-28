#include "Alumno.h"
#include <cstring>
#include <iostream>

using namespace std;

Alumno::Alumno(){
    this->nombre = NULL;
    this->apellido = NULL;
    this->especialidad = NULL;
}

Alumno::Alumno(const Alumno &orig){
    this->SetCodigo(orig.codigo);
    this->SetNombre(orig.nombre);
    this->SetApellido(orig.apellido);
    this->SetEspecialidad(orig.especialidad);
    this->SetCraest(orig.craest);
}

Alumno::Alumno(char *linea){
    this->nombre = NULL;
    this->apellido = NULL;
    this->especialidad = NULL;
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


Alumno::Alumno(int codigo, char* nombre, char* apellido, char *especialidad, double craest){
    //cout << "Constructor Alumno..." << endl;
    this->SetCodigo(codigo);
    this->SetNombre(nombre);
    this->SetApellido(apellido);
    this->SetEspecialidad(especialidad);
    this->SetCraest(craest);
}

Alumno::~Alumno() {
    //cout << "Destructor Alumno..." << endl;
}

void Alumno::SetCraest(double craest) {
    if (craest > 0.0)
        this->craest = craest;
}

double Alumno::GetCraest(){
    return craest;
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

// Esta NO es una función miembro (método)
ostream& operator<< (ostream& out, const Alumno &alu){
    out << alu.codigo << " " << alu.nombre << " " << alu.apellido << " " << alu.especialidad << " " << alu.craest;
    return out;
}

bool Alumno::operator>(const Alumno &alumno){
    return this->codigo > alumno.codigo;
}

bool Alumno::operator==(const Alumno &alumno){
    return this->codigo == alumno.codigo;
}

Alumno Alumno::operator=(const Alumno &orig){
    this->SetCodigo(orig.codigo);
    this->SetNombre(orig.nombre);
    this->SetApellido(orig.apellido);
    this->SetEspecialidad(orig.especialidad);
    this->SetCraest(orig.craest);
    return *this;
}

void Alumno::imprimirIdentidad(){
    cout << "Alumno: " << this->nombre << endl;
}