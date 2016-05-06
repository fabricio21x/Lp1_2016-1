#include "Universidad.h"
#include "Curso.h"
#include "Alumno.h"

#include <iostream>
using namespace std;

void leerDatos(void *&cursos, void *&alumnos){
    int numCursos, codAlumno;
    
    codAlumno = leeCursos(cursos, numCursos);
    //imprimirCursos(cursos, numCursos);
    
    leerAlumnos(alumnos, codAlumno);
    //imprimirAlumnos(alumnos);
}

void agregarNotas(void *&lstAlumnos){
    char buffCurso[10];
    int codAlumno, nota;
    int indAlum;
    
    void **arrAlumnos = (void **)lstAlumnos;
    
    cin.clear();
    while (cin >> buffCurso >> codAlumno >> nota){
        char *codCurso = new char[strlen(buffCurso) + 1];
        strcpy(codCurso, buffCurso);
        indAlum = buscarAlumno(arrAlumnos, codAlumno);
        agregarNotaCurso(arrAlumnos[indAlum], codCurso, nota);
//        void **regAlumno = (void **)arrAlumnos[indAlum];
//        if (regAlumno[3] == NULL)
//            cout << "gg" << endl;
    }
    imprimirAlumnosNotas(lstAlumnos);
}


