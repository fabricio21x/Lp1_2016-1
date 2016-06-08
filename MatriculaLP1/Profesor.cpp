#include "Profesor.h"
#include <iostream>

using namespace std;

Profesor::Profesor() {
    inicializarProfesor();
}

Profesor::Profesor(const Profesor &orig){
    inicializarProfesor();
    this->SetCodigo(orig.codigo);
    this->SetNombre(orig.nombre);
    this->SetApellido(orig.apellido);
    this->SetEspecialidad(orig.especialidad);
    this->SetTipo(orig.tipo);
}

Profesor Profesor::operator=(const Profesor &orig){
    inicializarProfesor();
    this->SetCodigo(orig.codigo);
    this->SetNombre(orig.nombre);
    this->SetApellido(orig.apellido);
    this->SetEspecialidad(orig.especialidad);
    this->SetTipo(orig.tipo);
    return *this;
}

void Profesor::inicializarProfesor(){
    this->nombre = NULL;
    this->apellido = NULL;
    this->especialidad = NULL;
    this->tipo = NULL;
}

Profesor::~Profesor() {
    delete[] this->nombre;
    delete[] this->apellido;
    delete[] this->especialidad;
    delete[] this->tipo;
}

void Profesor::SetTipo(char* tipo) {
    this->SetCadena(this->tipo, tipo);
}

char* Profesor::GetTipo() {
    return this->CopiarCadena(this->tipo);;
}

void Profesor::SetEspecialidad(char* especialidad) {
    this->SetCadena(this->especialidad, especialidad);
}

char* Profesor::GetEspecialidad() {
    return this->CopiarCadena(this->especialidad);
}

void Profesor::SetApellido(char* apellido) {
    this->SetCadena(this->apellido, apellido);
}

char* Profesor::GetApellido() {
    return this->CopiarCadena(this->apellido);
}

void Profesor::SetNombre(char* nombre) {
    this->SetCadena(this->nombre, nombre);
}

char* Profesor::GetNombre() {
    return this->CopiarCadena(this->nombre);
}

void Profesor::SetCodigo(int codigo) {
    this->codigo = codigo;
}

int Profesor::GetCodigo() {
    return codigo;
}

void Profesor::SetCadena(char *&miCadena, char *nuevaCadena){
    if (miCadena != NULL)
        delete[] miCadena;
    miCadena = new char[strlen(nuevaCadena) + 1];
    strcpy(miCadena, nuevaCadena);
}

char *Profesor::CopiarCadena(char *miCadena){
    char *copiaCadena = new char[strlen(miCadena) + 1];
    strcpy(copiaCadena, miCadena);
    return copiaCadena;
}


istream& operator>>(istream &in,Profesor &prof){
    int codigo;
    char nombre[30], apellido[30], especialidad[30], tipo[30];
    
    in >> codigo >> nombre >> apellido >> especialidad >> tipo;
    prof.codigo = codigo;
    prof.nombre = nombre;
    prof.apellido = apellido;
    prof.especialidad = especialidad;
    prof.tipo = tipo;
    
    return in;
}

ostream& operator<<(ostream &out,const Profesor &prof){
    out << prof.codigo << ' ' << prof.nombre << ' ' << prof.apellido << ' ' 
            << prof.especialidad << ' ' << prof.tipo << endl;
    
    return out;
}
