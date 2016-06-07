/* 
 * File:   Profesor.h
 * Author: fernandoalva
 *
 * Created on May 24, 2016, 11:33 PM
 */

#ifndef PROFESOR_H
#define	PROFESOR_H
#include <iostream>

using namespace std;

class Profesor {
public:
    Profesor();
    ~Profesor();
    
    void SetTipo(char* tipo);
    char* GetTipo();
    
    void SetEspecialidad(char* especialidad);
    char* GetEspecialidad();
    
    void SetApellido(char* apellido);
    char* GetApellido();
    
    void SetNombre(char* nombre);
    char* GetNombre();
    
    void SetCodigo(int codigo);
    int GetCodigo();
    
    friend istream& operator>>(istream &in, Profesor &prof);
    friend ostream& operator<<(ostream &out,const Profesor &prof);
    
private:
    int codigo;
    char *nombre;
    char *apellido;
    char *especialidad;
    char *tipo;
    
    void SetCadena(char *&, char *);
    char *CopiarCadena(char *);
};

#endif	/* PROFESOR_H */

