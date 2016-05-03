#include <iostream>
#include "functions.h"
#include "util.h"
#include "aux.h"
#include <cstring>

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

void separaDatos(char *linea, char *&nomAlumno, int &especialidad){
    char *palabras[100];
    char buffNombre[100] = {};
    int numPal;
    
    split(linea, palabras, numPal);
    
    especialidad = atoi(palabras[numPal - 1]);
    
    strcat(buffNombre, palabras[0]);
    for (int i = 1; i < numPal-1; i++) {
        strcat(buffNombre, " ");
        strcat(buffNombre, palabras[i]);
    }
    nomAlumno = new char[strlen(buffNombre) + 1];
    strcpy(nomAlumno, buffNombre);
}

void leerDatos(void *&lstCursos, void *&lstAlumnos){
    
    void *buffCursos[400];
    void *buffAlumnos[400];
    char linea[500];
    int numCurso = 0, codAlumno, numAlumno=0, especialidad;
    char *codCurso, *nomCurso, *nomAlumno;
    double credCurso;
    
    while(!(cin >> codAlumno)){
        cin.clear();
        cin.getline(linea, 400, '\n');
        separaDatos(linea, codCurso, nomCurso, credCurso);
        buffCursos[numCurso++] = colocarDatos(codCurso, nomCurso, credCurso);
    }
    lstCursos = memoriaExacta(buffCursos, numCurso);
    
    cin.getline(linea, 400, '\n');
    separaDatos(linea, nomAlumno, especialidad);
    buffAlumnos[numAlumno++] = colocarDatos(codAlumno, nomAlumno, especialidad);
    
    while(cin >> codAlumno){
        cin.getline(linea, 400, '\n');
        separaDatos(linea, nomAlumno, especialidad);
        buffAlumnos[numAlumno++] = colocarDatos(codAlumno, nomAlumno, especialidad);
    }
    lstAlumnos = memoriaExacta(buffAlumnos, numAlumno);
}

void agregarNotas(void *&lstAlumnos){
    void **arrAlumnos = (void **)lstAlumnos;
    char buffCurso[10];
    int codAlumno, nota, indAlum;
    
    while(cin >> buffCurso >> codAlumno >> nota){
        char *codCurso = new char[strlen(buffCurso) + 1];
        strcpy(codCurso, buffCurso);
        indAlum = buscarAlumno(arrAlumnos,codAlumno);
        agregarNotaCurso(arrAlumnos[indAlum], codCurso, nota);
    }
}

void imprimirDatos(void *lstCursos, void *lstAlumnos){
    void **arrCursos = (void **)lstCursos; //en si lstCursos es un triple puntero a void
    void **arrAlumnos = (void **)lstAlumnos;
    
    cout << "CURSOS: " <<endl;
    for (int i = 0; arrCursos[i] != NULL; i++) {
        void **regCurso = (void **)arrCursos[i];
        
        char *ptrCodigo = (char *)regCurso[0];
        char *ptrNombre = (char *)regCurso[1];
        double *ptrCred = (double *)regCurso[2];
        
        cout << ptrCodigo << '\t' << ptrNombre << '\t' << *ptrCred << endl;
    }
    
    cout << "ALUMNOS: " << endl;
    for (int i = 0; arrAlumnos[i] != NULL; i++) {
        void **regAlumno = (void **)arrAlumnos[i];
        
        int *ptrCod = (int *)regAlumno[0];
        char *ptrNombre = (char *)regAlumno[1];
        int *ptrEsp = (int *)regAlumno[2];
        
        char **cursos = (char **)regAlumno[3];
        int *notas = (int *)regAlumno[4];
        int *cant = (int *)regAlumno[5];

        cout << *ptrCod << "  " << ptrNombre << "\t" << *ptrEsp << endl;
        cout << "Notas por curso: \n";
        for (int i = 0; i < cant[1]; i++) {
            cout << '\t' << cursos[i] << '\t' << notas[i] << endl;
        }

        
    }
}