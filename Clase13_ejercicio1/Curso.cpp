#include <iostream>
#include "Curso.h"
#include "util.h"

using namespace std;

void separaDatos(char *linea, char *&codCurso, char *&nomCurso, double &credCurso){
    char *palabras[100];
    char buffNombre[100] = {};
    int numPal;
    
    split(linea,palabras,numPal);
    codCurso = new char[strlen(palabras[0]) + 1];
    strcpy(codCurso, palabras[0]);
    
    credCurso = atof(palabras[numPal - 1]);
    
    strcat(buffNombre, palabras[1]);
    for (int i = 2; i < numPal-1; i++) {
        strcat(buffNombre, " ");
        strcat(buffNombre, palabras[i]);
    }
    
    nomCurso = new char[strlen(buffNombre) + 1];
    strcpy(nomCurso, buffNombre);
}

void *colocarCurso(char *codCurso, char *nomCurso, double credCurso){
    void **regCurso = new void*[3];
    //necesito crear un puntero y darle memoria(para que se mantenga) a 
    //credCurso para poderlo guardar en el arreglo de punteros
    double *ptrCred = new double; 
    *ptrCred = credCurso;
    
    regCurso[0] = codCurso; //ya se le dio memoria en separaDatos
    regCurso[1] = nomCurso; //ya se le dio memoria en separaDatos
    regCurso[2] = ptrCred;
    
    return regCurso;
}

void leeCursos(void *&lstCursos){
    
    void *buffCursos[400];
    char linea[500];
    int numCurso = 0;
    char *codCurso, *nomCurso;
    double credCurso;
    
    while(cin.getline(linea, 400, '\n')){
        separaDatos(linea, codCurso, nomCurso, credCurso);
        buffCursos[numCurso++] = colocarCurso(codCurso, nomCurso, credCurso);
    }
    lstCursos = memoriaExacta(buffCursos, numCurso);
}

void imprimirCursos(void *lstCursos){
    void **arrCursos = (void **)lstCursos; //en si lstCursos es un triple puntero a void
    
    for (int i = 0; arrCursos[i] != NULL; i++) {
        void **regCurso = (void **)arrCursos[i];
        
        char *ptrCodigo = (char *)regCurso[0];
        char *ptrNombre = (char *)regCurso[1];
        double *ptrCred = (double *)regCurso[2];
        
        cout << ptrCodigo << '\t' << ptrNombre << '\t' << *ptrCred << endl;
    }

}