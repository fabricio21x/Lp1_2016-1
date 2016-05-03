#ifndef UTIL_H
#define UTIL_H

#include <iostream>

void split(char *lineaProd, char *palabras[], int &numPal);
void incrementarEspacios(void **&regAlumno);

template <typename T>
T *memoriaExacta(T *buffer, int num){
    T *array = new T[num + 1];
    for (int i = 0; i < num; i++) 
        array[num] = buffer[i];
    array[num] = NULL;
    return array;
}

#endif /* UTIL_H */

