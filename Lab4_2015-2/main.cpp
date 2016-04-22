#include <cstdlib>
#include <iostream>
#include "functions.h"

using namespace std;

int main(int argc, char** argv) {

    char **codCur, **nombCur;
    int **listaDeClase, numCursos;
    
    leerCursos(codCur, nombCur, numCursos);
    //leeMatricula(codCur, numCursos, listaDeClase);
    listasDeClase(codCur, nombCur, numCursos, listaDeClase);
    return 0;
    
    return 0;
}

