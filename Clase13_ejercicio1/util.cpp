#include "util.h"
#include <iostream>

using namespace std;

void split(char *linea, char *palabras[], int &numPal){
    char *pal;
    numPal = 0;
    pal = strtok(linea, " \t");
    while(pal){
        palabras[numPal++] = pal;
        pal = strtok(NULL, " \t\n");
    }
}

void *memoriaExacta(void *buffCursos[], int numCurso){
    void **arrCursos = new void*[numCurso + 1];
    for (int i = 0; i < numCurso; i++) {
        arrCursos[i] = buffCursos[i];
    }
    arrCursos[numCurso] = NULL;
    return arrCursos;
}
