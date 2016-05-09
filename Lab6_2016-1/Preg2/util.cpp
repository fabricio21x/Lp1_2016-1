//fabricio monsalve 21031411
#include "util.h"
#include <cstring>
#include <iostream>

using namespace  std;

void split(char linea[], char*palabras[], int &numPal){
    char *pal;
    numPal = 0;
    palabras[numPal++] = strtok(linea, " \t\r");
    while((pal = strtok(NULL, " \t"))){
        palabras[numPal++] = pal;
    }
}

void *memoriaExacta(void *buff[], int num){
    void **array = new void*[num + 1]; //se le da un espacio mas para poner NULL en el final, para usarlo como delimitador
    for (int i = 0; i < num; i++) {
        array[i] = buff[i];
    }
    array[num] = NULL; //se coloca el delimitador que nos indicara que acabaron los datos
    return array;    
}

void incrementarEspacios(void *&ciudad){
    void **regCiud = (void**)ciudad;
    
    void **regDatos = (void **)regCiud[2];
    
    int *num = (int *)regDatos[0]; //se lee el total de espacios
    
    void **auxCiud = new void*[*num + 5];
    
    for (int i = 0; i < *num; i++){
        auxCiud[i] = regDatos[i];
    }
    delete[] regDatos; //se borra la referencia al arreglo antiguo
    *num += 5;
    auxCiud[0] = num; //se aumenta el total de espacios disponibles
    regCiud[2] = auxCiud; //se hace apuntar al nuevo arreglo con espacios aumentados
}