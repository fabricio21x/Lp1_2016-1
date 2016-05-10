#include <cstdlib>
#include "functions.h"

using namespace std;

int main(int argc, char** argv) {

    void *vendedores;
    
    leerDatos(vendedores);
    reporteDeVentas(vendedores);
    
    return 0;
}

