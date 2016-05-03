#include "util.h"
#include <iostream>

using namespace std;

void split(char *lineaProd, char *palabras[], int &numPal){
    char *pal;
    numPal = 0;
    while(cin.peek() == ' '){
        cin.ignore();
    }
    pal = strtok(lineaProd, " \t");
    while(pal){
        palabras[numPal++] = pal;
        pal = strtok(NULL, " \t\n");
    }
    cin.ignore();
}

void incrementarEspacios(void **&regAlumno){
    char **cursos = (char **)regAlumno[3];
    int *notas = (int *)regAlumno[4];
    int *cantidades = (int *)regAlumno[5];
    
    char **auxCursos = new char*[cantidades[0] + 5];
    int *auxNotas = new int[cantidades[0] + 5];
    
    for (int i = 0; i < cantidades[1]; i++) {
        auxCursos[i] = cursos[i];
        auxNotas[i] = notas[i];
    }
    cantidades[0] += 5;
    
    delete[] cursos;
    delete[] notas;
    
    regAlumno[3] = auxCursos;
    regAlumno[4] = auxNotas;
}