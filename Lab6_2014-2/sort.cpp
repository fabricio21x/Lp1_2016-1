#include "sort.h"
#include <iostream>

using namespace std;


int divide(int array[], int start, int end){
    int left, right, pivot, temp;
    
    pivot = array[start];
    left = start;
    right = end;
    
    while(left < right){
        while(array[right] > pivot)
            right--;
        while((left < right) && (array[left] <= pivot))
            left++;
        if (left < right){
            temp = array[left];
            array[left] = array[right];
            array[right] = temp;
        }
    }
    temp = array[right];
    array[left] = array[start];
    array[start] = temp;
    
    return right;   
    
}
void quickSort(int array[], int start, int end){
    int pivot;
    
    if (start < end){
        pivot = divide(array, start, end);
        quickSort(array,start, pivot - 1);
        quickSort(array, pivot + 1, end);        
    }    
}

