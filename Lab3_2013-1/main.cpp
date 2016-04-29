#include <cstdlib>
#include <iostream>
#include "functions.h"

using namespace std;


int main(int argc, char** argv) {

    int **caracteristicas, **coordenadas, numPolig;
    
    numPolig = leePoligonos(caracteristicas, coordenadas);
    imprimeDatos(caracteristicas, coordenadas, numPolig);
    return 0;
}

