#include "Util.h"
#include <cstring>

void ourSplit(char *lineaProd, char *palabras[], int &numPal){
    char *pal;
    numPal = 0;
    pal = strtok(lineaProd, " \t");
    while(pal){
        palabras[numPal++] = pal;
        pal = strtok(NULL, " \t");
    }
}

void incrementarEspacios(double *&montosProd){
    double *auxMontosProd = new double[(int)montosProd[0] + 10];
    for (int i = 0; i < (int)montosProd[1]; i++)
        auxMontosProd[i] = montosProd[i];
    auxMontosProd[0] = (int)montosProd[0] + 10;
    delete[] montosProd;
    montosProd = auxMontosProd; 
}