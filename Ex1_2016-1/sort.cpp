//FABRICIO MONSALVE ESCUDERO 20131411
#include "sort.h"
#include <iostream>

void quickSort(void *&array, int start, int end, int(*comp)(const void*, const void*)){
    int pivot;
    if(start < end){
        pivot = divide(array, start, end, comp);
        quickSort(array,start, pivot - 1, comp);
        quickSort(array, pivot + 1, end, comp);
    }
}


int divide(void *&array, int start, int end, int(*comp)(const void*, const void*)){
    int left, right;
    void *temp;
    
    void **arrAux = (void **)array;

    //pivot = arrAux[start];
    left = start;
    right = end;
    while (left < right){
        while (comp(arrAux[start],arrAux[right]) < 0) //mientras el pivot es menor que el extremo derecho
            right--;
        
        while ((left < right) && (comp(arrAux[left],arrAux[start]) > 0))//mientras el pivot es mayor que el extremo izquiero
            left++;
        
        if(left < right){ //si aun no se cruzan se prosigue intercambiando
            temp = arrAux[left]; 
            arrAux[left] = arrAux[right];
            arrAux[right] = temp;

        }            
    }
    //los indices ya se cruzaron
    
    temp = arrAux[right];
    arrAux[right] = arrAux[start];
    arrAux[start] = temp;   
    
    array = arrAux;
    return right; //posicion del pivot
}


