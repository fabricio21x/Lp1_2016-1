#include <cstdlib>
#include "functions.h"

using namespace std;

int main(int argc, char** argv) {

    void *alumnos, *cursos;
    
    leerDatos(cursos,alumnos);
    //agregarNotas(alumnos);
    imprimirDatos(cursos, alumnos);
    
    return 0;
}

