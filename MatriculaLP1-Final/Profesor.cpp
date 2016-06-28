#include "Profesor.h"
#include <iostream>

using namespace std;

Profesor::Profesor() {
    inicializarProfesor();
}

Profesor::Profesor(int codigo, char *nombre, char *apellido, char *especialidad, char *tipo):Persona(codigo, nombre, apellido, especialidad){
    inicializarProfesor();
    this->SetTipo(tipo);
}

Profesor::Profesor(const Profesor &orig){
    //cout << "En el constructor copia de Profesor" << endl;
//    *this = orig;
    inicializarProfesor();
    this->SetCodigo(orig.codigo);
    this->SetNombre(orig.nombre);
    this->SetApellido(orig.apellido);
    this->SetEspecialidad(orig.especialidad);
    this->SetTipo(orig.tipo);
}

Profesor Profesor::operator=(const Profesor &orig){
    //cout << "En el =" << endl;
    inicializarProfesor();
    this->SetCodigo(orig.codigo);
    this->SetNombre(orig.nombre);
    this->SetApellido(orig.apellido);
    this->SetEspecialidad(orig.especialidad);
    this->SetTipo(orig.tipo);
    return *this;
}

void Profesor::inicializarProfesor(){
    this->tipo = NULL;
}

Profesor::~Profesor() {
    cout << "Destructor de Profesor" << endl;
    delete[] this->tipo;
}

void Profesor::SetTipo(char* tipo) {
    this->SetCadena(this->tipo, tipo);
}

char* Profesor::GetTipo() {
    return this->CopiarCadena(this->tipo);
}

// Esta NO es una función miembro (método)
ostream& operator<< (ostream& out, const Profesor &prof){
    out << prof.codigo << " " << prof.nombre << " " << prof.apellido << " " << prof.especialidad << " " << prof.tipo;
    return out;
}

void Profesor::imprimirIdentidad(){
    cout << "Profesor: " << this->nombre << endl;
}