/* 
 * File:   Omnibus.h
 * Author: fabricioandres
 *
 * Created on June 21, 2016, 8:23 AM
 */

#ifndef OMNIBUS_H
#define OMNIBUS_H
#include <vector>
#include "Pasajero.h"

using namespace std;

class Omnibus {
public:
    Omnibus();
    Omnibus(const Omnibus& orig);
    virtual ~Omnibus();
    int GetNumAsientos() const;
    char* GetChofer() const;
    char* GetPlaca() const;
    void SetNumAsientos(int numAsientos);
    void SetChofer(char* chofer);
    void SetPlaca(char* placa);
    void AgregarRuta(char* ruta);
    
    bool BuscarRuta(char *destino);
    int AsientosOcupados();
    Omnibus& operator=(const Omnibus &omn);
    void AgregarPasajero(int, char*, char*);
    void ImprimirRutas();
    
    friend bool operator<(const Omnibus &omn1, const Omnibus &omn2);
    void ordenarPasajeros();
    void ImprimirPasajerosXRuta();
    
private:
    char* placa;
    char* chofer;
    int numAsientos;
    vector<char*>ruta;
    vector<Pasajero> pasajeros;
    void inicializaBus();
    
    void SetCadena(char *&miCadena, char *nuevaCadena);
    char* CopiarCadena(char *miCadena) const;
};

#endif /* OMNIBUS_H */

