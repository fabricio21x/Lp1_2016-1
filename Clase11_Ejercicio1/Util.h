/* 
 * File:   Util.h
 * Author: fernandoalva
 *
 * Created on April 19, 2016, 8:56 AM
 */

#ifndef UTIL_H
#define	UTIL_H

#include <iostream>

void ourSplit(char *lineaProd, char *palabras[], int &numPal);

void incrementarEspacios(double *&montosProd);

template <typename T>
T *memoriaExacta (T *buff, int num){
    T *arr = new T[num + 1];
    for (int i = 0; i < num; i++)
        arr[i] = buff[i];
    arr[num] = NULL;
    return arr;
}

#endif	/* UTIL_H */

