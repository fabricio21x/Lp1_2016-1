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

void incrementarEspacios(void **&regCiud){
    //void **regCiud = (void**) ciudad;
    
    int *num = (int *)regCiud[0]; //se lee el total de espacios
    int *num2 = (int *)regCiud[1];
    void **auxCiud = new void*[*num + 5];
    
    for (int i = 0; i < *num; i++) {
        auxCiud[i] = regCiud[i];
    }
    delete[] regCiud;
    *num += 5;
    auxCiud[0] = num; //se aumenta el total de espacios disponibles
    auxCiud[1] = num2;
    regCiud = auxCiud;
}