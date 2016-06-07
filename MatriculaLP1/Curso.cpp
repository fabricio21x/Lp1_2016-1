#include "Curso.h"
#include "Alumno.h"
#include "Profesor.h"

Curso::Curso(string codigo,double creditos, int vacantes, string nombre){
    this->SetCodigo(codigo);
    this->SetNombre(nombre);
    this->numAlumnos = 0;
    this->lstAlumnos = new Alumno[vacantes];
    this->creditos = creditos;
    this->vacantes = vacantes;
}

Curso::~Curso() {
    
}

void Curso::SetCreditos(double creditos) {
    if (creditos > 0)
        this->creditos = creditos;
}

double Curso::GetCreditos() const{
        return creditos;
}

void Curso::SetNombre(string nombre) {
    this->nombre = nombre;
}

string Curso::GetNombre() const {
    return nombre;
}

void Curso::SetCodigo(string codigo){
    this->codigo = codigo;
}

string Curso::GetCodigo() const{
    return codigo;
}

void Curso::SetProfesor(Profesor profesor) {
    this->profesor = profesor;
}

void Curso::SetVacantes(int vacantes) {
    if (vacantes > 0)
        this->vacantes = vacantes;
}

int Curso::GetVacantes() const {
    return vacantes;
}

Curso Curso::operator+(Alumno &alum){
    this->lstAlumnos[this->numAlumnos++] = alum;
    return *this;
}

ostream& operator<<(ostream &out,const Curso &cur){
    out << cur.codigo << " " << cur.nombre << " " << cur.creditos << endl;
    out << "Profesor: " << cur.profesor << endl;
    out << "Lista de Alumnos: " << endl;
    
    if (cur.numAlumnos != 0){
        for (int i = 0; i < cur.numAlumnos; i++) {
            out << cur.lstAlumnos[i];
        }
    }
    return out;
}



