#ifndef UTIL_H
#define UTIL_H

#include <iostream>

using namespace std;

void split(char *lineaProd, char *palabras[], int &numPal);
void memoriaExacta(int **&array, int **buffer, int num);

//template <typename T>
//T *memoriaExacta(T *buffer, int num){
//    T *array = new T[num + 1];
//    for (int i = 0; i < num; i++){
//        array[num] = buffer[i];
//        cout << buffer[i] << endl;
//    }
//    array[num] = NULL;
//    return array;
//}

#endif /* UTIL_H */

