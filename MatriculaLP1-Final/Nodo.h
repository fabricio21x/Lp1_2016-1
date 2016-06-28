#ifndef NODO_H
#define NODO_H

template <class T>
class Lista; 

template <class T>
class Nodo {
public:
    Nodo(T elem);
    Nodo(const Nodo& orig);
    virtual ~Nodo();
    
    friend class Lista<T>;
private:
    T elem;
    Nodo<T> *sig;
};

#endif /* NODO_H */
//--------------------------------
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
