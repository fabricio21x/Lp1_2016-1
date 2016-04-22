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

void incrementarEspacios(int *&alumnoClase){
    int *auxAlumnoclase = new int[alumnoClase[0] + 5];
    for (int i = 0; i < alumnoClase[1]; i++)
        auxAlumnoclase[i] = alumnoClase[i];
    auxAlumnoclase[0] = alumnoClase[0] + 10;
    delete[] alumnoClase;
    alumnoClase = auxAlumnoclase;
}