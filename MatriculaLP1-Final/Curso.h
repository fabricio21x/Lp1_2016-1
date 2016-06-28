#ifndef CURSO_H
#define	CURSO_H

#include "Alumno.h"
#include "Profesor.h"

#include <string>
using namespace std;

class Curso {
public:
    
    Curso(string codigo, double creditos, int numVacantes, string nombre = "");
    
    ~Curso();
    
    void SetCreditos(double creditos);
    double GetCreditos() const;
    
    void SetNombre(string nombre);
    string GetNombre() const;
    
    void SetCodigo(string codigo);
    string GetCodigo() const;
       
    void SetNumVacantes(int numVacantes);
    int GetNumVacantes() const;
    
    void SetProfesor(Profesor profesor);
    Profesor GetProfesor() const;
    
    
    friend ostream& operator<< (ostream& out, const Curso &curso);
    Curso operator+ (Alumno &alumno);
    
private:
    string codigo;
    string nombre;
    double creditos;
    
    Profesor profesor;
    Alumno *lstAlumnos;
    int cantAlumnos;
    int numVacantes;
};

#endif	/* CURSO_H */

