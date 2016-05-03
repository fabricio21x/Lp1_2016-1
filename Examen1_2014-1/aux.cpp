#include "aux.h"
#include "util.h"
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

int buscarAlumno(void **arrAlumnos, int codAlumno){
    for (int i = 0; arrAlumnos[i] != NULL; i++){
        void **regAlumno = (void**)arrAlumnos[i];
        
        if(*(int*)regAlumno[0] == codAlumno) //se castea como int* y luego se accede a su contenido con otro *
            return i;
    }
    return -1;
}

int buscarCurso(char **codigos,char *codCurso, int cant){
    for (int i = 0; i<cant; i++)
        if(strcmp(codigos[i],codCurso)==0)
            return i;
    
    return -1;
}

void crearListaCursos(void **&regAlumno, char *codCurso,int nota){
    void **auxAlumno = new void*[6];
    
    //pasar lo que ya estaba en el arreglo
    auxAlumno[0] = regAlumno[0];
    auxAlumno[1] = regAlumno[1];
    auxAlumno[2] = regAlumno[2];
    
    //se crean las nuevas estructuras para codCurso, notas y tamaños, dar memoria a lo nuevo
    char** cursos = new char*[5];
    cursos[0] = codCurso;
    auxAlumno[3] = cursos;
    
    int *notas = new int[5];
    notas[0] = nota;
    auxAlumno[4] = notas;
    
    int *cantidades = new int[2];
    cantidades[0] = 5;
    cantidades[1] = 1;
    auxAlumno[5] = cantidades;    
}

void agregarNotaCurso(void *&alumno,char *codCurso,int nota){
    void **regAlumno = (void **)alumno;
    int indCurso;
    
    if(regAlumno[3] == NULL){
        crearListaCursos(regAlumno,codCurso,nota);
    }else {
        char **cursos = (char**)regAlumno[3];
        int *notas = (int *)regAlumno[4];
        int *cantidades = (int *)regAlumno[5];
        
        indCurso = buscarCurso(cursos, codCurso, cantidades[1]);
        
        if(indCurso == -1){//no existe el curso
            if(cantidades[0] == cantidades[1]){//si esta lleno
                incrementarEspacios(regAlumno);
                cursos[cantidades[1]] = codCurso;
                notas[cantidades[1]] = nota;
                cantidades[1]++;
            }
        }else {
            if(notas[indCurso] < nota){
                notas[indCurso] = nota;
            }
        }
    }
    
}
