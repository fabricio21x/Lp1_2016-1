/* 
 * File:   main.cpp
 * Author: fernandoalva
 *
 * Created on April 19, 2016, 8:24 AM
 */

#include <cstdlib>
#include "Producto.h"
using namespace std;

int main() {
    char **codigo, **descripcion;
    int *stock;
    double *pu, **montos;
    
    creaEstructuras(codigo, descripcion, stock, pu, montos);
    imprimeEstructuras(codigo, descripcion, stock, pu, montos);
    return 0;
}

