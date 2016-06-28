/* 
 * File:   Profesor.h
 * Author: fernandoalva
 *
 * Created on May 24, 2016, 11:33 PM
 */

#ifndef PROFESOR_H
#define	PROFESOR_H

#include "Persona.h"
#include <iostream>
using namespace std;

class Profesor:public Persona {
public:
    Profesor();
    Profesor(int codigo, char *nombre, char *apellido, char *especialidad, char *tipo);
    
    Profesor(const Profesor &orig);
    virtual ~Profesor();
    
    
    void SetTipo(char* tipo);
    char* GetTipo();
    
    friend ostream& operator<< (ostream& out, const Profesor &prof);
    
    Profesor operator=(const Profesor &orig);
    
    virtual void imprimirIdentidad();
    
    
private:
    char *tipo;
    void inicializarProfesor();
};

#endif	/* PROFESOR_H */

