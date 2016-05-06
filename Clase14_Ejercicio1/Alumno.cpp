#include <iostream>
#include <cstring>
#include "Alumno.h"
#include "Util.h"

using namespace std;

void separaDatosAlumno(char linea[], char *&nomAlumno, int &codEsp){
    char *palabras[500], buffNombre[500] = {};
    int numPalabras;
    
    ourSplit(linea, palabras, numPalabras);
    
    
    codEsp = atoi(palabras[numPalabras-1]);
    
    strcat(buffNombre, palabras[0]);
    for (int i = 1; i < numPalabras-1; i++){
        strcat(buffNombre, " ");
        strcat(buffNombre, palabras[i]);
    }
    nomAlumno = new char[strlen(buffNombre) + 1];
    strcpy(nomAlumno, buffNombre);
}

void *colocarAlumno(int codAlumno, char *nomAlumno, int codEsp){
    void **regAlumno = new void*[4];
    
    int *ptrCodigo = new int;
    *ptrCodigo = codAlumno;
    
    int *ptrEsp = new int;
    *ptrEsp = codEsp;
    
    regAlumno[0] = ptrCodigo;
    regAlumno[1] = nomAlumno;
    regAlumno[2] = ptrEsp;
    regAlumno[3] = NULL;
    
    return regAlumno;
}


void leerAlumnos(void *&alumnos, int codAlumno){
    char linea[500]; int numAlumnos = 0;
    char *nomAlumno; int codEsp;
    
    void *buffAlumnos[500];
    
    do{
        cin.getline(linea, 500, '\n');
        separaDatosAlumno(linea, nomAlumno, codEsp);
        buffAlumnos[numAlumnos++] = colocarAlumno(codAlumno, nomAlumno, codEsp);
    }while (cin >> codAlumno);
    
    alumnos = memoriaExacta(buffAlumnos, numAlumnos);
}

void imprimirAlumnos(void *alumnos){
    void **arrAlumnos = (void **)alumnos;
    
    for (int i = 0; arrAlumnos[i]; i++){
        void **regAlumno = (void **)arrAlumnos[i];
        int *ptrCodigo = (int *)regAlumno[0];
        char *ptrNombre = (char *)regAlumno[1];
        int *ptrEsp = (int *)regAlumno[2];
        cout << *ptrCodigo << '\t' << ptrNombre << '\t' << *ptrEsp << endl;
    }
}


int buscarAlumno(void **arrAlumnos, int codAlumno){
    for (int i = 0; arrAlumnos[i]; i++){
        void **regAlumno = (void **)arrAlumnos[i];
        if (*(int *)regAlumno[0] == codAlumno) 
            return i;
    }
    return -1;
}

void crearListaCursos(void *&alumno, char *codCurso, int nota){
    void **regAlumno = (void **)alumno;
    
    void **auxAlumno = new void*[6];
    // Pasar lo repetido
    auxAlumno[0] = regAlumno[0];
    auxAlumno[1] = regAlumno[1];
    auxAlumno[2] = regAlumno[2];
    // Dar memoria a lo nuevo
    char **cursos = new char*[5];
    cursos[0] = codCurso;
    auxAlumno[3] = cursos;
    
    int *notas = new int[5];
    notas[0] = nota;
    auxAlumno[4] = notas;
    
    int *cantidades = new int[2];
    cantidades[0] = 5;
    cantidades[1] = 1;
    auxAlumno[5] = cantidades;
    
    alumno = auxAlumno;

}


int buscarCurso(char **cursos, int cantCursos, char *codCurso){
    for (int i = 0; i< cantCursos; i++)
        if (strcmp(codCurso, cursos[i]) == 0) return i;
    return -1;
}

void agregarNotaCurso(void *&alumno, char *codCurso, int nota){
    void **regAlumno = (void **)alumno;
    int indCurso;
    
    if (regAlumno[3] == NULL){
        crearListaCursos(alumno, codCurso, nota);
    }else{
        char **cursos = (char **)regAlumno[3];
        int *notas = (int *)regAlumno[4];
        int *cantidades= (int *)regAlumno[5];
        
        indCurso = buscarCurso(cursos, cantidades[1], codCurso);
        if (indCurso == -1){ // No existe el curso
            if (cantidades[0] == cantidades[1]){ // Si está lleno
                incrementarEspacios(alumno);
                // Actualizar las referencias de la variables locales
                cursos = (char **)regAlumno[3];
                notas = (int *)regAlumno[4];
            }
            cursos[cantidades[1]] = codCurso;
            notas[cantidades[1]] = nota;
            cantidades[1]++;
        }else{// Existe el curso
            if (notas[indCurso] < nota) 
                notas[indCurso] = nota;
        }
    }
    
}


void imprimirAlumnosNotas(void *lstAlumnos){
    void **arrAlumnos = (void **)lstAlumnos;
    for (int i=0; arrAlumnos[i]; i++){
        void **regAlumno = (void **)arrAlumnos[i];
        int *codAlumno = (int *)regAlumno[0];
        char *nomAlumno = (char *)regAlumno[1];
        int *codEspe = (int *)regAlumno[2];
        cout << *codAlumno << '\t' << nomAlumno << '\t' << *codEspe << endl;
        
        if (regAlumno[3]){
           char **cursos = (char **)regAlumno[3];
            int *notas = (int *)regAlumno[4];
            int *cantidades = (int *) regAlumno[5];
        
            for (int j=0; j<cantidades[1]; j++)
                cout << '\t' << cursos[j] << '\t' <<  notas[j] << endl; 
        }
    }
}