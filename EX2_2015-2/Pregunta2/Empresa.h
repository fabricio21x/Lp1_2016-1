/* 
 * File:   Empresa.h
 * Author: fabricioandres
 *
 * Created on June 21, 2016, 8:23 AM
 */

#ifndef EMPRESA_H
#define EMPRESA_H
#include "Omnibus.h"

using namespace std;

class Empresa {
public:
    Empresa(int, char*, char*);
    Empresa(const Empresa& orig);
    virtual ~Empresa();
    int GetNumBuses() const;
    char* GetDireccion() const;
    int GetRuc() const;
    char* GetNombre() const;
    
    void LeerRuta();
    void LeerPasajeros();
    void ImprimirReporte();
private:
    char* nombre;
    int ruc;
    char* direccion;
    int numBuses;
    vector<Omnibus> flota;
    void separarDatosRuta(char *);
    void separarDatosPasajeros(char linea[]);
    int BuscarPosicion(char *);
    void imprimirRutas();
};

#endif /* EMPRESA_H */

