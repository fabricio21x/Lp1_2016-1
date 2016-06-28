/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Persona.h
 * Author: fernandoalva
 *
 * Created on June 8, 2016, 9:09 AM
 */

#ifndef PERSONA_H
#define PERSONA_H

class Persona {
public:
    Persona();
    Persona(int codigo, char *nombre, char *apellido, char *especialidad);
    Persona(const Persona& orig);
    virtual ~Persona();
    
    void SetEspecialidad(char* especialidad);
    char* GetEspecialidad() const;
    
    void SetApellido(char* apellido);
    char* GetApellido() const;
    
    void SetNombre(char* nombre);
    char* GetNombre() const;
    
    void SetCodigo(int codigo);
    int GetCodigo() const;
    
    virtual void imprimirIdentidad() = 0;
    
private:    
    void inicializarPersona();
    
protected:
    int codigo;
    char *nombre;
    char *apellido;
    char *especialidad;
    
    void SetCadena(char *&, char *);
    char *CopiarCadena(char *) const;
};

#endif /* PERSONA_H */

