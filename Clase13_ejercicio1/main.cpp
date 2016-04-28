#include <iostream>
#include "Curso.h"

using namespace std;

int main(int argc, char** argv) {

    void *cursos;
    
    leeCursos(cursos);
    imprimirCursos(cursos);
    
    return 0;
}

