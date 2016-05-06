#include <cstdlib>
#include <iostream>
#include "functions.h"

using namespace std;

int main(int argc, char** argv) {

    
    void *medicos, *ingresosFecha;
    double *ingresosMedicos;
    
    leerMedicos(medicos);
    leerConsultas(medicos,ingresosFecha,ingresosMedicos);
    
    return 0;
}

