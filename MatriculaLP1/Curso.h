#ifndef CURSO_H
#define	CURSO_H

#include <string>
#include "Alumno.h"
#include "Profesor.h"
using namespace std;

class Curso {
public:
    Curso(string codigo, double cred, int numVac , string nombre = "");
    
    ~Curso();
    
    void SetCreditos(double creditos);
    double GetCreditos() const;
    
    void SetNombre(string nombre);
    string GetNombre() const;
    
    void SetCodigo(string codigo);
    string GetCodigo() const;
    
    void SetVacantes(int vacantes);
    int GetVacantes() const;
    
    void SetProfesor(Profesor profesor);
    
    Curso operator+(Alumno &alum);
    friend ostream& operator<<(ostream &out,const Curso &cur);
private:
    string codigo;
    string nombre;
    double creditos;
    Profesor profesor;
    Alumno *lstAlumnos;
    int numAlumnos;
    int vacantes;
};

#endif	/* CURSO_H */

