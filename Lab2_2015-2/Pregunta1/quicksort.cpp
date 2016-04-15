 #include "quicksort.h"

// Función para dividir el array y hacer los intercambios
int divide(int fechas[300], double array[100], int start, int end) {
    int left;
    int right;
    double pivot;
    double temp;
    
    int diaTemp, mesTemp, anioTemp;
 
    pivot = array[start];
    left = start;
    right = end;
 
    // Mientras no se cruzen los índices
    while (left < right) {
        while (array[right] > pivot) {
            right--;
        }
 
        while ((left < right) && (array[left] <= pivot)) {
            left++;
        }
 
        // Si todavía no se cruzan los indices seguimos intercambiando
        if (left < right) {
            temp = array[left];
            array[left] = array[right];
            array[right] = temp;
            
            diaTemp = fechas[left*3];
            mesTemp = fechas[left*3 + 1];
            anioTemp = fechas[left*3 + 2];
            
            fechas[left*3] = fechas[right*3];
            fechas[left*3 + 1] = fechas[right*3 + 1];
            fechas[left*3 + 2] = fechas[right*3 + 2];
            
            fechas[right*3] = diaTemp;
            fechas[right*3 + 1] = mesTemp;
            fechas[right*3 + 2] = anioTemp;
            
        }
    }
 
    // Los índices ya se han cruzado, ponemos el pivot en el lugar que le corresponde
    temp = array[right];
    array[right] = array[start];
    array[start] = temp;
    
    diaTemp = fechas[right*3];
    mesTemp = fechas[right*3 + 1];
    anioTemp = fechas[right*3 + 2];

    fechas[right*3] = fechas[start*3];
    fechas[right*3 + 1] = fechas[start*3 + 1];
    fechas[right*3 + 2] = fechas[start*3 + 2];

    fechas[start*3] = diaTemp;
    fechas[start*3 + 1] = mesTemp;
    fechas[start*3 + 2] = anioTemp;
 
    // La nueva posición del pivot
    return right;
}
 
// Función recursiva para hacer el ordenamiento
void quicksort(int fechas[300], double array[100], int start, int end){
    int posPivot;
 
    if (start < end) {
        posPivot = divide(fechas, array, start, end);
 
        // Ordeno la lista de los menores
        quicksort(fechas, array, start, posPivot - 1);
 
        // Ordeno la lista de los mayores
        quicksort(fechas, array, posPivot + 1, end);
    }
}







int divide(double tiempo[200], int array[200], int start, int end){
    int left;
    int right;
    double pivot;
    int temp;
    double tempD;
 
    pivot = tiempo[start];
    left = start;
    right = end;
 
    // Mientras no se cruzen los índices
    while (left < right) {
        while (tiempo[right] > pivot) {
            right--;
        }
 
        while ((left < right) && (tiempo[left] <= pivot)){
            left++;
        }
 
        // Si todavía no se cruzan los indices seguimos intercambiando
        if (left < right) {
            temp = array[left];
            array[left] = array[right];
            array[right] = temp;
            
            tempD = tiempo[left];
            tiempo[left] = tiempo[right];
            tiempo[right] = tempD;
        }
    }
 
    // Los índices ya se han cruzado, ponemos el pivot en el lugar que le corresponde
    temp = array[right];
    array[right] = array[start];
    array[start] = temp;
    
    tempD = tiempo[right];
    tiempo[right] = tiempo[start];
    tiempo[start] = tempD;
 
    // La nueva posición del pivot
    return right;
}
 
// Función recursiva para hacer el ordenamiento
void quicksort(double tiempo[200], int array[200], int start, int end){
    int pivot;
 
    if (start < end) {
        pivot = divide(tiempo,array, start, end);
 
        // Ordeno la lista de los menores
        quicksort(tiempo,array, start, pivot - 1);
 
        // Ordeno la lista de los mayores
        quicksort(tiempo,array, pivot + 1, end);
    }
}