#include "stack.h"
#include <iostream>

//FABRICIO MONSALVE 20131411
using namespace std;
const int DEFSIZE = 5;
void Stack_create(int *&stack){
    stack = new int[DEFSIZE + 2]; //para guardar en [0] el tamaño y el [1] el ultimo añadido
    for (int i = 0; i < sizeof stack; i++) //inicializo todo el stackeglo en null
        stack[i] = NULL;
    
    stack[0] = 0;
    stack[1] = 0;
}

void Stack_push(int *&stack, int item){
    if (stack[0] != 0){ //en caso el arreglo no sea vacio
        stack[++stack[1]] = item;
        stack[0]++;     
    }else{
        stack[2] = item;
        stack[0]++;
        stack[1] = 2;
    }  
}

int Stack_pop(int *&stack, int &item){
    if (stack[0] != 0){ //en caso el arreglo no sea vacio
        item = stack[stack[1]--];
        stack[0]--;
        return 1;
    }else{ //caso la pila este vacia, se retorna 0
        item = 0;
        return 0;
    }
}

bool Stack_isEmpty(int *&stack){
    return (stack[0] == 0);
}

int Stack_size(int *&stack){
    return stack[0];
}

void Stack_resize(int *&stack){
    int *auxStack = new int[stack[0] + DEFSIZE];
    
    for (int i = 0; i < (stack[0] + DEFSIZE + 2); i++) //lleno la nueva pila con NULL
        auxStack[i] = NULL;
    
    for (int i = 0; i < (stack[0] + 2); i++) { //paso los datos de la pila anterior a la neuva
        auxStack[i]=stack[i];
    }
    delete[] stack;
    stack = auxStack; 
}




void Stack_create(double *&stack){
    stack = new double[DEFSIZE + 2]; //para guardar en [0] el tamaño y el [1] el ultimo añadido
    for (int i = 0; i < (DEFSIZE + 2); i++) //inicializo todo el stackeglo en null
        stack[i] = NULL;
    
    stack[0] = 0.0;
    stack[1] = 0.0;
}

void Stack_push(double *&stack, double item){
    if (stack[0] != 0){ //en caso el arreglo no sea vacio
        stack[(int)++stack[1]] = item;
        stack[0]++;

    }else{
        stack[2] = item;
        stack[0]++;
        stack[1] = 2;
    }
    
}

int Stack_pop(double *&stack, double &item){
    if (stack[0] != 0){ //en caso el arreglo no sea vacio
        item = stack[(int)stack[1]--];
        stack[0]--;
        return 1;
    }else{ //caso la pila este vacia, se retorna 0
        item = 0;
        return 0;
    }
}

bool Stack_isEmpty(double *&stack){
    return ((int)stack[0] == 0);
}

int Stack_size(double *&stack){
    return ((int)stack[0]);
}

void Stack_resize(double *&stack){
    double *auxStack = new double[(int)stack[0] + DEFSIZE + 2];
    
    for (int i = 0; i < ((int)stack[0] + DEFSIZE + 2); i++) //lleno la nueva pila con NULL
        auxStack[i] = NULL;
    
    for (int i = 0; i < (int)stack[0]; i++) { //paso los datos de la pila anterior a la neuva
        auxStack[i]=stack[i];
    }
    delete[] stack;
    stack = auxStack; 
}