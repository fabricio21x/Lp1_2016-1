#include "Util.h"
#include <iostream>

using namespace std;

void ourSplit(char *linea, char *palabras[], int &numPal){
    char *pal; numPal = 0;
    palabras[numPal++] = strtok(linea, " \t");
    while((pal = strtok(NULL, " \t"))){
        palabras[numPal++] = pal;
    }
}

void *memoriaExacta(void *buffCursos[], int numCurso){
    void** arrCursos = new void*[numCurso + 1];
    for (int i = 0; i < numCurso; i++)
        arrCursos[i] = buffCursos[i];
    arrCursos[numCurso] = NULL;
    return arrCursos;
}

void incrementarEspacios(void *&alumno){
    void **regAlumno = (void **)alumno;
    
    char **cursos = (char **)regAlumno[3];
    int *notas = (int *)regAlumno[4];
    int *cantidades = (int *) regAlumno[5];
    
    char **auxCursos = new char*[cantidades[0] + 5];
    int *auxNotas = new int[cantidades[0] + 5];
    
    for (int i = 0; i < cantidades[1]; i++){
        auxCursos[i] = cursos[i];
        auxNotas[i] = notas[i];
    }
    cantidades[0]+=5;
    
    delete[] cursos;
    delete[] notas;
     
    regAlumno[3] = auxCursos;
    regAlumno[4] = auxNotas;
}
