
//FABRICIO MONSALVE ESCUDERO 20131411
#include <cstdlib>
#include <cstdio>
#include "functions.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    printf("%80s","REGISTRO CLIMATOLOGICO DEL PAIS\n");
    impLinea('=',125);
    printf("    %-20s %-20s %-20s %-20s %-20s %-20s\n","CIUDAD","CODIGO","FECHA","TEMPERATURA","HUMEDAD","PRECIPITACIONES");
    printf("       %64s    %s %17s %23s %s\n","°C","°F","%","TIEMPO(seg)","CANTIDAD");
    impLinea('-',125);
    
    while(leerCiudad()){ //mientras hayan ciudades por leer
    }
    
    return 0;
}

