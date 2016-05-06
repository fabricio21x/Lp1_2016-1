#include "util.h"
#include <iostream>

using namespace std;

void split(char *linea, char *palabras[], int &numPal){
    char *pal;
    numPal = 0;
    palabras[numPal++] = strtok(linea, " \t");
    while((pal = strtok(NULL, " \t"))){        
        palabras[numPal++] = pal;
    }
}

void splitCons(char *linea, char *palabras[], int &numPal){
    char *pal;
    numPal = 0;
    palabras[numPal++] = strtok(linea, " \t");
    while((pal = strtok(NULL, " \t"))){        
        palabras[numPal++] = pal;
        if(numPal == 3) break;
    }
}



void *memoriaExacta(void *buff[], int num){
    void **array = new void*[num + 1];
    for (int i = 0; i < num; i++) {
        array[i] = buff[i];
    }
    array[num] = NULL;
    return array;
}
