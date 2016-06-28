/* 
 * File:   Cono.h
 * Author: fabricioandres
 *
 * Created on June 14, 2016, 9:41 AM
 */

#ifndef CONO_H
#define CONO_H
#include "Circulo.h"

class Cono:public Circulo {
public:
    Cono(double = 0.0, double = 0.0);
    Cono(const Cono& orig);
    virtual ~Cono();
    void SetAltura(double altura);
    double GetAltura() const;
    
    double volumen();
    void imprimirDatos();
private:
    double altura;
};

#endif /* CONO_H */

