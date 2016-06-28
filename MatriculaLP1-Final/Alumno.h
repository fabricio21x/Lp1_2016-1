/* 
 * File:   Alumno.h
 * Author: fernandoalva
 *
 * Created on May 24, 2016, 8:36 AM
 */

#ifndef ALUMNO_H
#define	ALUMNO_H

#include "Persona.h"
#include <iostream>
using namespace std;

class Alumno:public Persona{
public:
    Alumno();
    
    Alumno(int codigo, char *nombre, char *apellido, char *especialidad, double craest);
    Alumno(char *linea);
    
    Alumno(const Alumno &orig);
    
    virtual ~Alumno();
    
    
    void SetCraest(double craest);
    double GetCraest();
    
    friend ostream& operator<< (ostream& out, const Alumno &alu);
    
    virtual void imprimirIdentidad();
    
    bool operator>(const Alumno &alumno);
    bool operator==(const Alumno &alumno);
    Alumno operator=(const Alumno &orig);
        
private:
    double craest;
    
    void SeparaDatos(char *linea, int &codigo, char *&nombre, char *&apellido, char *&especialidad, double &craest);
};

#endif	/* ALUMNO_H */

