//FABRICIO MONSALVE 20131411
#include "functions.h"
#include <cstdlib>

using namespace std;

int main(int argc, char** argv) {

    void *contribuyentes;
    leerDatos(contribuyentes);
    ordenarDatos(contribuyentes);
    reporte(contribuyentes);
    return 0;
}

