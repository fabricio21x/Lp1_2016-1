#include <iostream>
#include "Curso.h"
#include "Util.h"

using namespace std;

void separaDatos(char *linea, char *&codCurso, char *&nomCurso, double &credCurso){
    char *palabras[500]; int numPal;
    
    ourSplit(linea, palabras, numPal);

    codCurso = new char[strlen(palabras[0]) + 1];
    strcpy(codCurso, palabras[0]);
    
    credCurso = atof(palabras[numPal-1]);
    
    char buffNombre[500] = {};
    strcat(buffNombre, palabras[1]);
    for (int i = 2; i < numPal - 1; i++){
        strcat(buffNombre, " ");
        strcat(buffNombre, palabras[i]);
    }
    nomCurso = new char[strlen(buffNombre) + 1];
    strcpy(nomCurso, buffNombre);
}

void *colocarCurso(char *codCurso, char *nomCurso, double credCurso){
    void **regCurso = new void*[3];
    
    double *ptrCredCurso = new double;
    *ptrCredCurso = credCurso;
    
    regCurso[0] = codCurso;
    regCurso[1] = nomCurso;
    regCurso[2] = ptrCredCurso;
   
    return regCurso;
}

int leeCursos(void *&lstCursos, int &numCurso){
    void *buffCursos[500];
    char linea[500];
    numCurso = 0;
    char *codCurso, *nomCurso; double credCurso;
    
    int codAlumno;
    while(!(cin >> codAlumno)){
        cin.clear();
        cin.getline(linea, 500, '\n');
        separaDatos(linea, codCurso, nomCurso, credCurso);
        buffCursos[numCurso++] = colocarCurso(codCurso, nomCurso, credCurso);
    }
    
    lstCursos = memoriaExacta(buffCursos, numCurso);
    return codAlumno;
}

void imprimirCursos(void *lstCursos, int numCursos){
    void **arrCursos = (void **)lstCursos;
    
    for (int i = 0; i < numCursos ;i++){
        void **regCurso = (void **) arrCursos[i];
        
        char *ptrCodigo = (char *)regCurso[0];
        char *ptrNombre = (char *)regCurso[1];
        double *ptrCred = (double *)regCurso[2];
        
        cout << ptrCodigo << '\t' << ptrNombre << '\t' << *ptrCred << endl;
    }
    
}
