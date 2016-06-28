#include "Curso.h"

Curso::Curso(string codigo, double creditos, int numVacantes, string nombre){
    this->SetCodigo(codigo);
    this->SetNombre(nombre);
    this->SetCreditos(creditos);
    this->SetNumVacantes(numVacantes);
    
    this->lstAlumnos = new Alumno[numVacantes];
    this->cantAlumnos = 0;    
}

void Curso::SetNumVacantes(int numVacantes) {
    this->numVacantes = numVacantes;
}

int Curso::GetNumVacantes() const {
    return numVacantes;
}

void Curso::SetProfesor(Profesor profesor) {
    //cout << "En el SetProfesor.." << endl;
    this->profesor = profesor;
}

Profesor Curso::GetProfesor() const {
    return profesor;
}

Curso::~Curso() {
    
}

void Curso::SetCreditos(double creditos) {
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

// Esta No es una función miembro (método)
ostream& operator<< (ostream& out, const Curso &curso){
    out << curso.codigo << " " << curso.nombre << " " << curso.creditos << endl;
    out << "Profesor: " << curso.profesor << endl;
    out << "Lista de Alumnos: " << endl;
    for (int i = 0; i  < curso.cantAlumnos; i++){
        out << curso.lstAlumnos[i] << endl;
    }
    return out;
}

// Esta SÍ es una función miembro
Curso Curso::operator+ (Alumno &alumno){
    if (this->cantAlumnos < this->numVacantes)
        this->lstAlumnos[this->cantAlumnos++] = alumno;
    return *this;
}

