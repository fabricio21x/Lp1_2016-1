//fabricio monsalve 21031411
#include "util.h"
#include <cstring>
#include <iostream>

using namespace  std;

void split(char linea[], char*palabras[], int &numPal){
    char *pal;
    numPal = 0;
    palabras[numPal++] = strtok(linea, " \t");
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