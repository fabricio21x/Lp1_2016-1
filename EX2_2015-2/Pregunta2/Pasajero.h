/* 
 * File:   Pasajero.h
 * Author: fabricioandres
 *
 * Created on June 21, 2016, 8:23 AM
 */

#ifndef PASAJERO_H
#define PASAJERO_H

class Pasajero {
public:
    Pasajero(int, char*,char*);
    Pasajero(const Pasajero& orig);
    virtual ~Pasajero();
    char* GetDestino() const;
    char* GetNombre() const;
    int GetDni() const;
    void SetDestino(char* destino);
    void SetNombre(char* nombre);
    void SetDni(int dni);
    
    Pasajero& operator=(const Pasajero &pas);
    friend bool operator<(const Pasajero &p1, const Pasajero &p2);
private:
    int dni;
    char* nombre;
    char* destino;
    char* CopiarCadena(char *miCadena) const;
    void SetCadena(char *&miCadena, char *nuevaCadena);
    void inicializarPasajero();
};

#endif /* PASAJERO_H */

