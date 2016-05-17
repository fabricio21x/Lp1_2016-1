//FABRICIO MONSALVE ESCUDERO 20131411
#include "bancos.h"
#include <cstring>

double calculaBancoA(char *cargaFam, double monto, int riesgo){
    int fCarga;
    double hRiesgo;
    
    (strcmp(cargaFam,"Si")==0) ? fCarga=1:fCarga=3;
    
    if(riesgo >= 1 && riesgo <= 2){
        hRiesgo = 1;
    }else if(riesgo >= 3 && riesgo <= 5){
        hRiesgo = 0.6;
    }else if(riesgo >= 6 && riesgo <= 7){
        hRiesgo = 0.2;
    }else
        hRiesgo = 0;
    
    return (4*monto*fCarga*hRiesgo)/(14*3);    
}

double calculaBancoB(char *cargaFam, double monto, int riesgo){
    int fCarga;
    double hRiesgo;
    
    (strcmp(cargaFam,"Si")==0) ? fCarga=1:fCarga=4;
    
    if(riesgo >= 1 && riesgo <= 2){
        hRiesgo = 1;
    }else 
        hRiesgo = 0;
    
    return (4*monto*fCarga*hRiesgo)/(14*3);  
}

double calculaBancoC(char *cargaFam, double monto, int riesgo){
    int fCarga;
    double hRiesgo;
    
    (strcmp(cargaFam,"Si")==0) ? fCarga=2:fCarga=3;
    
    if(riesgo == 1){
        hRiesgo = 1;
    }else if(riesgo >= 2 && riesgo <= 4){
        hRiesgo = 0.4;
    }else
        hRiesgo = 0;
    
    return (4*monto*fCarga*hRiesgo)/(14*3);  
}
