//fabricio monsalve 20131411

#include <cstdlib>
#include "functions.h"

using namespace std;

int main(int argc, char** argv) {

    void *ciudades;
    int codigo;
    
    leerCiudades(ciudades, codigo);
    agregarDatosClima(ciudades, codigo);
    
    return 0;
}

