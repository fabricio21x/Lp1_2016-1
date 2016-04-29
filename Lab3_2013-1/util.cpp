#include "util.h"
#include <iostream>

using namespace std;

void split(char *lineaProd, char *palabras[], int &numPal){
    char *pal;
    numPal = 0;
    pal = strtok(lineaProd, " \t");
    while(pal){
        palabras[numPal++] = pal;
        pal = strtok(NULL, " \t");
    }
}

void memoriaExacta(int **&array, int **buffer, int num){
    int **arrAux = new int*[num + 1];
    for (int i = 0; i < num; i++) {
        arrAux[i] = buffer[i];
    }
    arrAux[num] = NULL;
    array = arrAux;
}
