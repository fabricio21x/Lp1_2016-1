#include "aux.h"
#include <iostream>

void *colocarDatos(char *codCurso, char *nomCurso, double credCurso){
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

void *colocarDatos(int codAlumno, char *nomAlumno, int especialidad){
    void **regAlumno = new void*[4];
    
    int *ptrEsp = new int;
    *ptrEsp = especialidad;
    
    int *ptrCod = new int;
    *ptrCod = codAlumno;
    
    regAlumno[0] = ptrCod;
    regAlumno[1] = nomAlumno;
    regAlumno[2] = ptrEsp;
    regAlumno[3] = NULL;
    
    return regAlumno;
}
