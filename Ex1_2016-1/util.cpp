//FABRICIO MONSALVE 20131411
#include <cstring>
#include "util.h"

void split(char linea[],char *palabras[],int &numPal){
    char *pal;
    pal = strtok(linea, ",");
    palabras[numPal++] = pal;
    while((pal = strtok(NULL, ","))){
        palabras[numPal++] = pal;
    }
}

void aumentarEspacios(void *&lstContr){
    void **arrContr = (void **)lstContr;    
    int *tot = (int *)arrContr[0];    
    void **auxContr = new void*[*tot + 5];
    
    for (int i = 0; i < *tot; i++) {
        auxContr[i] = arrContr[i];
    }
    delete[] arrContr;
    tot = (int *)auxContr[0];
    *tot += 5;
    auxContr[0] = tot;
    lstContr = auxContr;
}