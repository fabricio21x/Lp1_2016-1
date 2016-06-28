/* 
 * File:   Circulo.h
 * Author: fabricioandres
 *
 * Created on June 14, 2016, 9:38 AM
 */
#ifndef CIRCULO_H
#define CIRCULO_H


class Circulo {
public:
    Circulo(double = 0.0);
    Circulo(const Circulo& orig);
    virtual ~Circulo();
    virtual double volumen() = 0;
    virtual void imprimirDatos() = 0;
protected:    
    double radio;
};

#endif /* CIRCULO_H */

