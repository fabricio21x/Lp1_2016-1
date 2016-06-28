#include "Nodo.h"
#include "Alumno.h"
#include <iostream>
using namespace std;

template <class T>
Nodo<T>::Nodo(T elem) {
    this->elem = elem;
    this->sig = NULL;
}

template <class T>
Nodo<T>::Nodo(const Nodo& orig) {
}

template <class T>
Nodo<T>::~Nodo() {
    
}


template class Nodo<Alumno>;
