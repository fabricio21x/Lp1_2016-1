/* 
 * File:   TroncoDeCono.h
 * Author: fabricioandres
 *
 * Created on June 14, 2016, 9:41 AM
 */

#ifndef TRONCODECONO_H
#define TRONCODECONO_H
#include "Circulo.h"

class TroncoDeCono:public Circulo {
public:
    TroncoDeCono(double = 0.0, double = 0.0, double = 0.0);
    TroncoDeCono(const TroncoDeCono& orig);
    virtual ~TroncoDeCono();
    void SetAltura(double altura);
    double GetAltura() const;
    void SetRadio2(double radio2);
    double GetRadio2() const;
    
    double volumen();
    void imprimirDatos();
private:
    double radio2;
    double altura;
};

#endif /* TRONCODECONO_H */

