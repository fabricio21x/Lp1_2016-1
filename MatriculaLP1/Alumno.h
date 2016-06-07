/* 
 * File:   Alumno.h
 * Author: fernandoalva
 *
 * Created on May 24, 2016, 8:36 AM
 */

#ifndef ALUMNO_H
#define	ALUMNO_H
#include <iostream>

using namespace std;

class Alumno {
public:
    Alumno();
    Alumno(int codigo, char *nombre, char *apellido);
    Alumno(char *linea);
    ~Alumno();
    
    void SetCraest(double craest);
    double GetCraest();
    
    void SetEspecialidad(char* especialidad);
    char* GetEspecialidad();
    
    void SetApellido(char* apellido);
    char* GetApellido();
    
    void SetNombre(char* nombre);
    char* GetNombre();
    
    void SetCodigo(int codigo);
    int GetCodigo();
    
    friend istream& operator>>(istream &in, Alumno &alum);
    friend ostream& operator<<(ostream &out,const Alumno &alum);
private:
    int codigo;
    char *nombre;
    char *apellido;
    char *especialidad;
    double craest;
    
    void SetCadena(char *&, char *);
    char *CopiarCadena(char *);
    void SeparaDatos(char *linea, int &codigo, char *&nombre, char *&apellido, char *&especialidad, double &craest);
};

#endif	/* ALUMNO_H */

