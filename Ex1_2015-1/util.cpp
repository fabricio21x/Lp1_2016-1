#include "util.h"
#include <iostream>

using namespace std;

void split(char *linea, char *palabras[], int &numPal){
    char *pal;
    pal = strtok(linea, " \t");
    palabras[numPal++] = pal;
    while((pal = strtok(NULL, " \t"))){
        palabras[numPal++] = pal;
    }
}

void aumentarEspacios(char **&codArt,int *&acum){
    
    char **auxCod = new char*[acum[0] + 5];
    int *auxAcum = new int[acum[0] + 5];
    
    for (int i = 0; i < acum[0]; i++) {
        auxCod[i] = codArt[i];
        auxAcum[i] = acum[i];
    }
    auxAcum[0] += 5;
    delete[] codArt;
    delete[] acum;
    
    acum = auxAcum;
    codArt = auxCod;
}

void *memoriaExacta(void *buff[], int cant){
    
    void **arrVend = (void **)buff;
    void **auxVend = new void*[cant + 1];
    for (int i = 0; i < cant; i++) {
        auxVend[i] = arrVend[i];
    }
    auxVend[cant] = NULL;
    return auxVend;
    
}